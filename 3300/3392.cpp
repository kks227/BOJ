#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 1<<16;

struct Vert{
	int x, y1, y2;
	bool type;
	Vert(): Vert(0, 0, 0, false){}
	Vert(int x1, int y3, int y4, bool type1): x(x1), y1(y3), y2(y4), type(type1){}
	bool operator <(const Vert &O){
		if(x != O.x) return x < O.x;
		return type < O.type;
	}
};

struct SegTree{
	int start, yoff[MAX], c[MAX], s[MAX];
	SegTree(){
		start = MAX/2;
		fill(yoff, yoff+start, 0);
		fill(yoff+start, yoff+MAX, 1);
		for(int i=start-1; i>0; i--)
			yoff[i] = yoff[i*2] + yoff[i*2+1];
		fill(c, c+MAX, 0);
		fill(s, s+MAX, 0);
	}
	void update(int l, int r, bool type){ update(l, r, type, 1, 0, start); }
	void update(int l, int r, bool type, int node, int nl, int nr){
		if(r <= nl || nr <= l);
		else if(l <= nl && nr <= r) c[node] += (type ? 1 : -1);
		else{
			int mid = (nl+nr)/2;
			update(l, r, type, node*2, nl, mid);
			update(l, r, type, node*2+1, mid, nr);
		}
		if(c[node]) s[node] = yoff[node];
		else if(node < start) s[node] = s[node*2] + s[node*2+1];
		else s[node] = 0;
	}
	int sum(int l, int r){ return sum(l, r, 1, 0, start); }
	int sum(int l, int r, int node, int nl, int nr){
		if(r <= nl || nr <= l) return 0;
		if(l <= nl && nr <= r) return s[node];
		int mid = (nl+nr)/2;
		return sum(l, r, node*2, nl, mid) + sum(l, r, node*2+1, mid, nr);
	}
};

int main(){
	int N;
	Vert v[20000];
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		v[i*2] = Vert(x1, y1, y2, true);
		v[i*2+1] = Vert(x2, y1, y2, false);
	}
	sort(v, v+N*2);
	int result = 0;
	SegTree ST;
	for(int i=0; i<N*2; i++){
		if(i > 0) result += ST.sum(0, MAX/2) * (v[i].x-v[i-1].x);
		ST.update(v[i].y1, v[i].y2, v[i].type);
	}
	printf("%d\n", result);
}