#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
struct P{
	int x, y;
	P(): P(0, 0){}
	P(int x1, int y1): x(x1), y(y1){}
	bool operator <(const P& p)const{
		if(y == p.y) return x < p.x;
		return y < p.y;
	}
	bool operator ==(const P& p)const{
		return x==p.x && y==p.y;
	}
};

bool compare(const P& p, const P& q){ return p.x < q.x; }
inline int pow2(int n){ return n*n; }
inline int dist(P p, P q){ return pow2(p.x - q.x) + pow2(p.y - q.y); }

int main(){
	int N;
	P p[100000];
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d %d", &p[i].x, &p[i].y);
	sort(p, p+N, compare);
	for(int i=1; i<N; i++)
		if(p[i] == p[i-1]){
			puts("0");
			return 0;
		}

	set<P> S;
	int result = dist(p[0], p[1]), start = 0;
	S.insert(p[0]);
	S.insert(p[1]);
	for(int i=2; i<N; i++){
		while(start < i){
			if(pow2(p[i].x - p[start].x) > result) S.erase(p[start++]);
			else break;
		}
		int d = (int)sqrt(result) + 1;
		auto lo = S.lower_bound(P(-20000, p[i].y-d));
		auto hi = S.upper_bound(P(20000, p[i].y+d));
		for(auto iter=lo; iter!=hi; iter++)
			result = min(result, dist(p[i], *iter));
		S.insert(p[i]);
	}
	printf("%d\n", result);
}