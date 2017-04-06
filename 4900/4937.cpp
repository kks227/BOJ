#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1000000;

vector<int> P;
char dp[MAX+1];

bool about(int n){
	char &ret = dp[n];
	if(ret != -1) return ret;
	if(n < 10) return ret = (n == 3 || n == 9);

	for(int p: P){
		if(p == n && p%10 != 3) return ret = false;
		if(p >= n) break;
		if(n%p == 0 && !about(p)) return ret = false;
	}
	return ret = true;
}

int main(){
	bool np[MAX+1] = {1, 1,};
	P.push_back(2);
	for(int i=4; i<=MAX; i+=2) np[i] = true;
	for(int i=3; i<MAX; i+=2){
		if(np[i]) continue;
		P.push_back(i);
		for(long long j=1LL*i*i; j<MAX; j+=i*2) np[j] = true;
	}
	fill(dp, dp+MAX+1, -1);

	while(1){
		int N;
		scanf("%d", &N);
		if(N == -1) break;
		printf("%d %s\n", N, about(N) ? "YES" : "NO");
	}
}