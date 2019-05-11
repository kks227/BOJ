#include <cstdio>
#include <cstring>
using namespace std;
const int MAX_N = 50;
const int MAX = MAX_N*MAX_N;
const int MAX_K = 2500;

int R, C, K, N, map[MAX_N][MAX_N], r[MAX], c[MAX];
char dp[MAX+1][MAX_K];

int f(int i, int j){
	return (i+1)*(R-i)*(j+1)*(C-j)%K;
}

bool restore(int n, int k){
	char &ret = dp[n][k];
	if(ret != -1) return ret;
	if(n == N) return ret = !k;
	return ret = restore(n+1, k) | restore(n+1, (k+f(r[n], c[n]))%K);
}

void trace(int n, int k){
	if(n == N) return;

	if(restore(n+1, k)){
		map[r[n]][c[n]] = 0;
		trace(n+1, k);
	}
	else{
		map[r[n]][c[n]] = 1;
		trace(n+1, (k+f(r[n], c[n]))%K);
	}
}

int main(){
	int s = 0;
	scanf("%d %d %d", &R, &C, &K);
	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j){
			scanf("%d", &map[i][j]);
			if(map[i][j] == 1) s = (s+f(i, j)) % K;
			else if(map[i][j] == -1){
				r[N] = i;
				c[N] = j;
				++N;
			}
		}
	}

	memset(dp, -1, sizeof(dp));
	bool result = restore(0, s);
	if(!result) puts("-1");
	else{
		puts("1");
		trace(0, s);
		for(int i = 0; i < R; ++i){
			for(int j = 0; j < C; ++j)
				printf("%d ", map[i][j]);
			puts("");
		}
	}
}