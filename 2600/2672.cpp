#include <cstdio>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
const int MAX = 1<<7;

struct Vert{
	double x;
	int y1, y2;
	bool type;
	Vert(): Vert(0, 0, 0, false){}
	Vert(double x1, int y3, int y4, bool type1): x(x1), y1(y3), y2(y4), type(type1){}
	bool operator <(const Vert &O){
		if(x != O.x) return x < O.x;
		return type < O.type;
	}
};

struct SegTree{
	double yoff[MAX], s[MAX];
	int c[MAX];
	SegTree(){
		fill(yoff, yoff+MAX, 0);
		fill(c, c+MAX, 0);
		fill(s, s+MAX, 0);
	}
	void construct(){
		for(int i=MAX/2-1; i>0; i--)
			yoff[i] = yoff[i*2] + yoff[i*2+1];
	}
	void update(int l, int r, bool type){ update(l, r, type, 1, 0, MAX/2); }
	void update(int l, int r, bool type, int node, int nl, int nr){
		if(r <= nl || nr <= l);
		else if(l <= nl && nr <= r) c[node] += (type ? 1 : -1);
		else{
			int mid = (nl+nr)/2;
			update(l, r, type, node*2, nl, mid);
			update(l, r, type, node*2+1, mid, nr);
		}
		if(c[node]) s[node] = yoff[node];
		else if(node < MAX/2) s[node] = s[node*2] + s[node*2+1];
		else s[node] = 0;
	}
	double sum(int l, int r){ return sum(l, r, 1, 0, MAX/2); }
	double sum(int l, int r, int node, int nl, int nr){
		if(r <= nl || nr <= l) return 0;
		if(l <= nl && nr <= r) return s[node];
		int mid = (nl+nr)/2;
		return sum(l, r, node*2, nl, mid) + sum(l, r, node*2+1, mid, nr);
	}
};

int main(){
	int N, ycnt = 0;
	set<double> yset;
	map<double, int> yn;
	double x1[30], y1[30], x2[30], y2[30], ymin, yprev;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%lf %lf %lf %lf", x1+i, y1+i, x2+i, y2+i);
		x2[i] += x1[i];
		y2[i] += y1[i];
		yset.insert(y1[i]);
		yset.insert(y2[i]);
		if(i == 0) ymin = y1[i];
		else ymin = min(ymin, y1[i]);
	}
	SegTree ST;
	for(double y: yset){
		if(y > ymin) ST.yoff[MAX/2+ycnt-1] = y - yprev;
		yprev = y;
		yn[y] = ycnt++;
	}
	ST.construct();

	Vert v[60];
	for(int i=0; i<N; i++){
		int y3 = yn[y1[i]], y4 = yn[y2[i]];
		v[i*2] = Vert(x1[i], y3, y4, true);
		v[i*2+1] = Vert(x2[i], y3, y4, false);
	}
	sort(v, v+N*2);

	double result = 0;
	for(int i=0; i<N*2; i++){
		if(i > 0) result += ST.sum(0, MAX/2) * (v[i].x-v[i-1].x);
		ST.update(v[i].y1, v[i].y2, v[i].type);
	}
	if(result == round(result)) printf("%.0lf\n", result);
	else printf("%.2lf\n", result);
}