#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 200000;
const int INF = 1e9;

int N, c[100], dp1[MAX], dp2[MAX];

int solve1(int n){
	int &ret = dp1[n];
	if(ret != -1) return ret;
	if(n == 0) return ret = 0;
	if(n < c[1]) return ret = n;
	ret = INF;
	for(int i = 1; i < N && n >= c[i]; ++i)
		ret = min(solve1(n-c[i]) + 1, ret);
	return ret;
}

int solve2(int n){
	int &ret = dp2[n];
	if(ret != -1) return ret;
	if(n == 0) return ret = 0;
	if(n < c[1]) return ret = n;
	int i = upper_bound(c, c+N, n) - c;
	return ret = solve2(n-c[--i]) + 1;
}

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		scanf("%d", c+i);
	fill(dp1, dp1+MAX, -1);
	fill(dp2, dp2+MAX, -1);
	for(int i = c[N-1] + c[N-2]; i > 0; --i){
		if(solve1(i) != solve2(i)){
			puts("No");
			return 0;
		}
	}
	puts("Yes");
}