#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P1;
typedef pair<long long, double> P2;
const int MAX = 300000/2;
const int ST_MAX = 1048576;
const int INF = 1000000000;

struct Line{
	int x1, y1, x2, y2;
	Line(): Line(0, 0, 0, 0){}
	Line(int x3, int y3, int x4, int y4): x1(x3), y1(y3), x2(x4), y2(y4){}
	// must be used with both wline
	bool operator <(const Line &O)const{ return x1 < O.x1; }
};

// min value segment tree
struct SegTree{
	int arr[ST_MAX], root[ST_MAX], size, start;
	void initialize(int n){
		size = n;
		start = 1;
		while(start < size) start *= 2;
		fill(arr, arr+MAX*2, INF);
		fill(root, root+MAX*2, -1);
	}
	void renew(int pos, int val){
		pos += start;
		arr[pos] = val;
		root[pos] = pos - start;
		while(pos > 1){
			pos /= 2;
			if(arr[pos*2] <= arr[pos*2+1]){
				arr[pos] = arr[pos*2];
				root[pos] = root[pos*2];
			}
			else{
				arr[pos] = arr[pos*2+1];
				root[pos] = root[pos*2+1];
			}
		}
	}
	P1 query(int l, int r){ /*printf("%d %d renew\n", l, r);*/ return query(l, r, 1, 0, start); }
	P1 query(int l, int r, int node, int nl, int nr){
		if(r<=nl || nr<=l) return P1(INF, -1);
		if(l<=nl && nr<=r) return P1(arr[node], root[node]);
		int mid = (nl+nr)/2;
		P1 pl = query(l, r, node*2, nl, mid);
		P1 pr = query(l, r, node*2+1, mid, nr);
		return (pl.first <= pr.first ? pl : pr);
	}
};



Line wline[MAX];
SegTree ST;
int N, K, X, lc[MAX], rc[MAX], parent[MAX], w[MAX], h[MAX], cnt[MAX];

void makeTree(int l, int r, int node, int lx, int rx){
	w[node] = rx - lx;
	// left child
	P1 pl = ST.query(l, node);
	if(pl.second > -1){
		int pivot = pl.second;
		lc[node] = pivot;
		parent[pivot] = node;
		makeTree(l, node, pivot, lx, wline[node].x1);
		h[lc[node]] = wline[lc[node]].y1 - wline[node].y1;
	}
	// right child
	P1 pr = ST.query(node+1, r);
	if(pr.second > -1){
		int pivot = pr.second;
		rc[node] = pivot;
		parent[pivot] = node;
		makeTree(node+1, r, pivot, wline[node].x2, rx);
		h[rc[node]] = wline[rc[node]].y1 - wline[node].y1;
	}
}

void getCnt(int node){
	if(lc[node] != -1){
		getCnt(lc[node]);
		cnt[node] += cnt[lc[node]];
	}
	if(rc[node] != -1){
		getCnt(rc[node]);
		cnt[node] += cnt[rc[node]];
	}
}

P2 getResult(int node){
	long long a = 1LL * w[node] * h[node];
	double t = 0, ct = 0;
	if(cnt[node] > 0){
		t = 1.0 * a / cnt[node];
		a = 0;
	}
	if(lc[node] != -1){
		P2 temp = getResult(lc[node]);
		a += temp.first;
		ct = max(ct, temp.second);
	}
	if(rc[node] != -1){
		P2 temp = getResult(rc[node]);
		a += temp.first;
		ct = max(ct, temp.second);
	}
	return P2(a, t+ct);
}



int main(){
	scanf("%d", &N);
	int x1, y1, x2, y2, W = N/2-1;
	ST.initialize(W);
	for(int i=0; i<N; i++){
		scanf("%d %d", &x2, &y2);
		if(i>0 && i%2==0){
			int ln = (i-1)/2;
			wline[ln] = Line(x1, y1, x2, y2);
			ST.renew(ln, y1);
		}
		x1 = x2; y1 = y2;
	}
	scanf("%d", &K);
	for(int i=0; i<K; i++){
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		int target = lower_bound(wline, wline+W, Line(x1, y1, x2, y2)) - wline;
		cnt[target] = 1;
	}
	X = wline[W-1].x2;

	P1 pRoot = ST.query(0, W);
	int rootLine = pRoot.second;
	w[rootLine] = X;
	h[rootLine] = pRoot.first;
	fill(parent, parent+W, -1);
	fill(lc, lc+W, -1);
	fill(rc, rc+W, -1);
	makeTree(0, W, rootLine, 0, X);
	getCnt(rootLine);
	P2 result = getResult(rootLine);
	printf("%.2lf\n%lld\n", result.second, result.first);
}