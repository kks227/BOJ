#include <cstdio>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<long long, long long> P;

map<P, bool> dp;

bool block(long long n, long long m){
	auto iter = dp.find(P(n, m));
	if(iter != dp.end()) return iter->second;
	
	bool ret = false;
	if(n%m == 0) ret = true;
	else if(n < m*2) ret = !block(m, n-m);
	else ret = true;
	return dp[P(n, m)] = ret;
}

int main(){
	long long N, M;
	scanf("%lld %lld", &N, &M);
	if(N < M) swap(N, M);
	puts(block(N, M) ? "win" : "lose");
}