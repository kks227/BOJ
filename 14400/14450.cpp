#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 100000;

int N, K, A[MAX], dp[MAX+1][21][3];

int hps(int pos, int k, int h){
	int &ret = dp[pos][k][h];
	if(ret != -1) return ret;
	if(pos == N) return ret = 0;

	ret = hps(pos+1, k, h) + ((h+1)%3 == A[pos]);
	if(k > 0){
		for(int i = 1; i < 3; ++i){
			int j = (h+i)%3;
			ret = max(hps(pos+1, k-1, j) + ((j+1)%3 == A[pos]), ret);
		}
	}
	return ret;
}

int main(){
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N; ++i){
		char c;
		scanf(" %c", &c);
		A[i] = (c == 'H' ? 0 : c == 'S' ? 1 : 2);
	}
	memset(dp, -1, sizeof(dp));
	int result = 0;
	for(int i = 0; i < 3; ++i)
		result = max(hps(0, K, i), result);
	printf("%d\n", result);
}