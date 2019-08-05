#include <cstdio>
#include <cstring>
#include <unordered_map>
using namespace std;
const int MAX = 10000001;
const int MAX_P = 8;

int p10[MAX_P] = {1};
unordered_map<int, int> dp;

int digit(int n, int p){
	if(dp.find(n*MAX_P+p) != dp.end()) return dp[n*MAX_P+p];
	if(p == 0) return dp[n*MAX_P+p] = 1;
	int ret = digit(n/10, p-1);
	if(n/10 != n%p10[p]) ret += digit(n%p10[p], p-1);
	return dp[n*MAX_P+p] = ret;
}

int main(){
	int N, k = 0;
	scanf("%d", &N);
	for(int i = 1; p10[i-1]*10 <= N; ++i){
		p10[i] = p10[i-1] * 10;
		k = i;
	}
	printf("%d\n", digit(N, k));
}