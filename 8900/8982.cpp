#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Line{
	int x1, y1, x2, y2;
	Line(): Line(0, 0, 0, 0){}
	Line(int x3, int y3, int x4, int y4): x1(x3), y1(y3), x2(x4), y2(y4){}
	// must be used with both wline
	bool operator <(const Line &O)const{ return x1 < O.x1; }
};

int N, K, X, lc[2500], rc[2500], parent[2500], w[2500], h[2500];
bool full[2500];
Line wline[2500];

void makeTree(int node, int l, int r, int lx, int rx){
	w[node] = rx - lx;
	// left child
	int pivot = -1, d = 40001;
	for(int i=l; i<node; i++){
		if(d > wline[i].y1){
			d = wline[i].y1;
			pivot = i;
		}
	}
	if(pivot != -1){
		lc[node] = pivot;
		parent[pivot] = node;
		makeTree(pivot, l, node, lx, wline[node].x1);
		h[lc[node]] = wline[lc[node]].y1 - wline[node].y1;
	}
	// right child
	pivot = -1; d = 40001;
	for(int i=node+1; i<r; i++){
		if(d > wline[i].y1){
			d = wline[i].y1;
			pivot = i;
		}
	}
	if(pivot != -1){
		rc[node] = pivot;
		parent[pivot] = node;
		makeTree(pivot, node+1, r, wline[node].x2, rx);
		h[rc[node]] = wline[rc[node]].y1 - wline[node].y1;
	}
}

bool getFull(int node){
	bool result = full[node];
	if(lc[node] != -1) result &= getFull(lc[node]);
	if(rc[node] != -1) result &= getFull(rc[node]);
	return full[node] = result;
}

int getWater(int node){
	int result = full[node] ? w[node]*h[node] : 0;
	if(lc[node] != -1) result += getWater(lc[node]);
	if(rc[node] != -1) result += getWater(rc[node]);
	return result;
}



int main(){
	scanf("%d", &N);
	int x1, y1, x2, y2, W = N/2-1;
	for(int i=0; i<N; i++){
		scanf("%d %d", &x2, &y2);
		if(i > 0 && i%2 == 0) wline[(i-1)/2] = Line(x1, y1, x2, y2);
		x1 = x2; y1 = y2;
	}
	scanf("%d", &K);
	fill(full, full+W, true);
	for(int i=0; i<K; i++){
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		int target = lower_bound(wline, wline+W, Line(x1, y1, x2, y2)) - wline;
		full[target] = false;
	}
	X = wline[W-1].x2;

	int root = -1, d = 40001;
	for(int i=0; i<W; i++){
		if(d > wline[i].y1){
			d = wline[i].y1;
			root = i;
		}
	}
	fill(w, w+W, 0);
	fill(h, h+W, 0);
	w[root] = X;
	h[root] = d;
	fill(parent, parent+W, -1);
	fill(lc, lc+W, -1);
	fill(rc, rc+W, -1);
	makeTree(root, 0, W, 0, X);
	getFull(root);
	printf("%d\n", getWater(root));
}