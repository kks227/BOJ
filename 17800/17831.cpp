#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 2000000;

int N, p[MAX], A[MAX];
long long dp[MAX][2];
vector<int> child[MAX];

long long mentor(int curr, bool flag){
	long long &ret = dp[curr][flag];
	if(ret != -1) return ret;
	ret = 0;
	long long cSum = 0;
	for(int next: child[curr])
		cSum += max(mentor(next, false), mentor(next, true));
	ret = cSum;
	if(flag){
		for(int next: child[curr])
			ret = max(cSum - max(mentor(next, false), mentor(next, true)) + mentor(next, false) + A[curr]*A[next], ret);
	}
	return ret;
}

int main(){
	scanf("%d", &N);
	for(int i = 1; i < N; ++i){
		scanf("%d", p+i);
		child[--p[i]].push_back(i);
	}
	for(int i = 0; i < N; ++i)
		scanf("%d", A+i);
	memset(dp, -1, sizeof(dp));
	printf("%lld\n", max(mentor(0, false), mentor(0, true)));
}