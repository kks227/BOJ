#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;
const int MAX = 50001;
const long long INF = 1e18;
typedef pair<int, int> P;

struct LinearFunc{ // f(x) = ax + b, x >= s
	long long a, b;
	double s;
	LinearFunc(): LinearFunc(1, 0){}
	LinearFunc(long long a1, long long b1): a(a1), b(b1), s(-INF){}
};

inline double cross(LinearFunc &f, LinearFunc &g){
	return (g.b-f.b)/(f.a-g.a);
}



int main(){
	int N;
	P rect1[MAX];
	scanf("%d", &N);
	priority_queue<P, vector<P>, greater<P>> PQ;
	for(int i = 0; i < N; ++i){
		int w, h;
		scanf("%d %d", &w, &h);
		rect1[i] = P(w, h);
	}
	sort(rect1, rect1+N);
	for(int i = 0; i < N; ++i)
		PQ.push(P(rect1[i].second, i));
	vector<P> rect2;
	bool merged[MAX] = {false,};
	for(int i = N-1; i >= 0; --i){
		if(merged[i]) continue;
		merged[i] = true;
		while(!PQ.empty() && PQ.top().first <= rect1[i].second){
			merged[PQ.top().second] = true;
			PQ.pop();
		}
		rect2.push_back(rect1[i]);
	}
	reverse(rect2.begin(), rect2.end());
	N = rect2.size();

	long long dp[MAX] = {0,};
	LinearFunc f[MAX];
	int top = 0, fpos = 0;
	for(int i = 1; i <= N; ++i){
		LinearFunc g(rect2[i-1].second, dp[i-1]);
		while(top > 0){
			g.s = cross(f[top-1], g);
			if(f[top-1].s < g.s) break;
			if(--top == fpos) --fpos;
		}
		f[top++] = g;

		long long x = rect2[i-1].first;
		while(fpos+1 < top && f[fpos+1].s < x) ++fpos;
		dp[i] = f[fpos].a * x + f[fpos].b;
	}
	printf("%lld\n", dp[N]);
}