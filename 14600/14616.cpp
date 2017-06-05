#include <cstdio>
#include <algorithm>
using namespace std;
const int ST_MAX = 1<<20;

struct Point{
	int x, y;
	Point(): Point(0, 0){}
	Point(int x1, int y1): x(x1), y(y1){}
	bool operator ==(const Point &O)const{ return 1LL*x*O.y == 1LL*y*O.x; }
	bool operator <(const Point &O)const{ return 1LL*x*O.y > 1LL*y*O.x; }
};

struct SegTree{
	int arr[ST_MAX], start;
	SegTree(){
		start = ST_MAX/2;
		fill(arr, arr+ST_MAX, 0);
	}
	void inc(int n){ arr[start+n]++; }
	void construct(){
		for(int i=start-1; i>0; i--)
			arr[i] = arr[i*2] + arr[i*2+1];
	}
	int sum(int s, int e){ return sum(s, e, 1, 0, start); }
	int sum(int s, int e, int node, int ns, int ne){
		if(e <= ns || ne <= s) return 0;
		if(s <= ns && ne <= e) return arr[node];
		int mid = (ns+ne)/2;
		return sum(s, e, node*2, ns, mid) + sum(s, e, node*2+1, mid, ne);
	}
};

int main(){
	int N, M, P = 0, x[3][100000], y[3][100000];
	Point p[300000];
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d %d %d %d", &x[0][i], &y[0][i], &x[1][i], &y[1][i]);
		p[P++] = Point(x[0][i], y[0][i]);
		p[P++] = Point(x[1][i], y[1][i]);
	}
	scanf("%d", &M);
	for(int i=0; i<M; i++){
		scanf("%d %d", &x[2][i], &y[2][i]);
		p[P++] = Point(x[2][i], y[2][i]);
	}
	sort(p, p+P);
	P = unique(p, p+P)-p;

	SegTree ST;
	int result = 0;
	for(int i=0; i<M; i++)
		ST.inc(lower_bound(p, p+P, Point(x[2][i], y[2][i])) - p);
	ST.construct();
	for(int i=0; i<N; i++){
		int a, b;
		if(Point(x[1][i], y[1][i]) < Point(x[0][i], y[0][i])){
			a = lower_bound(p, p+P, Point(x[1][i], y[1][i])) - p;
			b = upper_bound(p, p+P, Point(x[0][i], y[0][i])) - p;
		}
		else{
			a = lower_bound(p, p+P, Point(x[0][i], y[0][i])) - p;
			b = upper_bound(p, p+P, Point(x[1][i], y[1][i])) - p;
		}
		if(ST.sum(a, b) == 0) result++;
	}
	printf("%d\n", result);
}