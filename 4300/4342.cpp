#include <cstdio>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

map<P, bool> dp;

bool block(int n, int m){
	auto iter = dp.find(P(n, m));
	if(iter != dp.end()) return iter->second;

	bool ret = false;
	if(n%m == 0) ret = true;
	else if(n < m*2LL) ret = !block(m, n-m);
	else ret = true;
	return dp[P(n, m)] = ret;
}

int main(){
	while(1){
		int N, M;
		scanf("%d %d", &N, &M);
		if(N == 0) break;

		if(N < M) swap(N, M);
		printf("%c wins\n", block(N, M) ? 'A' : 'B');
	}
}