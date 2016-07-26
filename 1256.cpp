#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int BIG = 1000000001;

int dp[101][101], p;
char result[201];
bool exist = true;

int words(int n, int m){
	int &ret = dp[n][m];
	if(ret != -1) return ret;
	if(n==0 || m==0) return ret = 1;
	return ret = min(words(n-1, m) + words(n, m-1), BIG);
}

void skip(int n, int m, int k){
	if(n == 0){
		for(int i=0; i<m; i++) result[p++] = 'z';
		return;
	}
	if(m == 0){
		for(int i=0; i<n; i++) result[p++] = 'a';
		return;
	}
	int pivot = words(n-1, m);
	if(k < pivot){
		result[p++] = 'a';
		skip(n-1, m, k);
	}
	else if(pivot < BIG){
		result[p++] = 'z';
		skip(n, m-1, k-pivot);
	}
	else exist = false;
}

int main(){
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	memset(dp, -1, sizeof(dp));
	if(K > words(N, M)) exist = false;
	else skip(N, M, K-1);
	printf("%s\n", exist ? result : "-1");
}