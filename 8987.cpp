#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> PII;
typedef pair<long long, int> PLI;
const int MAX = 300000/2;
const int ST_MAX = 1048576;
const int INF = 2000000000;

struct Line{
	int x1, y1, x2, y2;
	Line(): Line(0, 0, 0, 0){}
	Line(int x3, int y3, int x4, int y4): x1(x3), y1(y3), x2(x4), y2(y4){}
	// must be used with both wline
	bool operator <(const Line &O)const{ return x1 < O.x1; }
};

// min value segment tree
struct SegTree{
	int minDepth[ST_MAX], root[ST_MAX], size, start;
	void initialize(int n){
		size = n;
		start = 1;
		while(start < size) start *= 2;
		fill(minDepth, minDepth+MAX*2, INF);
		fill(root, root+MAX*2, -1);
	}
	void renewDepth(int pos, int val){
		pos += start;
		minDepth[pos] = val;
		root[pos] = pos - start;
		while(pos > 1){
			pos /= 2;
			if(minDepth[pos*2] <= minDepth[pos*2+1]){
				minDepth[pos] = minDepth[pos*2];
				root[pos] = root[pos*2];
			}
			else{
				minDepth[pos] = minDepth[pos*2+1];
				root[pos] = root[pos*2+1];
			}
		}
	}
	PII getMinDepth(int l, int r){ return getMinDepth(l, r, 1, 0, start); }
	PII getMinDepth(int l, int r, int node, int nl, int nr){
		if(r<=nl || nr<=l) return PII(INF, -1);
		if(l<=nl && nr<=r) return PII(minDepth[node], root[node]);
		int mid = (nl+nr)/2;
		PII pl = getMinDepth(l, r, node*2, nl, mid);
		PII pr = getMinDepth(l, r, node*2+1, mid, nr);
		return (pl.first <= pr.first ? pl : pr);
	}
};



Line wline[MAX];
SegTree ST;
int N, K, X, lc[MAX], rc[MAX], parent[MAX], w[MAX], h[MAX];
long long area[MAX], water[MAX];
bool leaked[MAX];

void makeTree(int l, int r, int node, int lx, int rx){
	w[node] = rx - lx;
	// left child
	PII pl = ST.getMinDepth(l, node);
	if(pl.second > -1){
		int pivot = pl.second;
		lc[node] = pivot;
		parent[pivot] = node;
		makeTree(l, node, pivot, lx, wline[node].x1);
		h[lc[node]] = wline[lc[node]].y1 - wline[node].y1;
	}
	// right child
	PII pr = ST.getMinDepth(node+1, r);
	if(pr.second > -1){
		int pivot = pr.second;
		rc[node] = pivot;
		parent[pivot] = node;
		makeTree(node+1, r, pivot, wline[node].x2, rx);
		h[rc[node]] = wline[rc[node]].y1 - wline[node].y1;
	}
}

void setWaterValue(int node){
	water[node] += area[node] = 1LL * w[node] * h[node];
	if(lc[node] != -1){
		water[lc[node]] += water[node];
		setWaterValue(lc[node]);
	}
	if(rc[node] != -1){
		water[rc[node]] += water[node];
		setWaterValue(rc[node]);
	}
}

void decreaseWaterValue(int node, long long value){
	if(leaked[node]) return;
	water[node] -= value;
	if(lc[node] != -1) decreaseWaterValue(lc[node], value);
	if(rc[node] != -1) decreaseWaterValue(rc[node], value);
}

void makeHole(int node, int child){
	leaked[node] = true;
	if(child != -1){
		if(lc[node] != -1 && lc[node] != child)
			decreaseWaterValue(lc[node], water[node]);
		else if(rc[node] != -1 && rc[node] != child)
			decreaseWaterValue(rc[node], water[node]);
	}
	water[node] = 0;
	int p = parent[node];
	if(p != -1 && !leaked[p]) makeHole(p, node);
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
			ST.renewDepth(ln, y1);
		}
		x1 = x2; y1 = y2;
	}
	X = wline[W-1].x2;

	PII pRoot = ST.getMinDepth(0, W);
	int rootLine = pRoot.second;
	w[rootLine] = X;
	h[rootLine] = pRoot.first;
	fill(parent, parent+W, -1);
	fill(lc, lc+W, -1);
	fill(rc, rc+W, -1);
	makeTree(0, W, rootLine, 0, X);
	setWaterValue(rootLine);

	priority_queue<PLI> PQ;
	for(int i=0; i<W; i++)
		if(lc[i] == -1 && rc[i] == -1) PQ.push(PLI(water[i], i));

	scanf("%d", &K);
	long long result = 0;
	for(int i=0; i<K; i++){
		PLI target(-1, -1);
		while(!PQ.empty()){
			PLI temp = PQ.top();
			PQ.pop();
			if(water[temp.second] != temp.first){
				PQ.push(PLI(water[temp.second], temp.second));
			}
			else if(!leaked[temp.second]){
				target = temp;
				break;
			}
		}
		if(target.second == -1) break;

		result += target.first;
		makeHole(target.second, -1);
	}
	printf("%lld\n", result);
}