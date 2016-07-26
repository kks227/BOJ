#include <cstdio>
#include <map>
using namespace std;
typedef map<long long, long long> LLM;

int P, Q;
LLM dp;

long long infSeq(long long n){
	LLM::iterator finder = dp.find(n);
	if(finder != dp.end()) return finder->second;
	return dp[n] = infSeq(n/P) + infSeq(n/Q);
}

int main(){
	long long N;
	scanf("%lld %d %d", &N, &P, &Q);
	dp[0] = 1;
	printf("%lld\n", infSeq(N));
}