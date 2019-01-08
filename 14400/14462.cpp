#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAX = 1000;

int N, L[MAX], R[MAX], dp[MAX+1][MAX+1];

int crosswalk(int l, int r){
	int &ret = dp[l][r];
	if(ret != -1) return ret;
	if(l == N || r == N) return ret = 0;

	ret = max(crosswalk(l+1, r), crosswalk(l, r+1));
	if(abs(L[l]-R[r]) <= 4) ret = max(crosswalk(l+1, r+1) + 1, ret);
	return ret;
}

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		scanf("%d", L+i);
	for(int i = 0; i < N; ++i)
		scanf("%d", R+i);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", crosswalk(0, 0));
}