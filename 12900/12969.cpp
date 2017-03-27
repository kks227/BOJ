#include <cstdio>
#include <cstring>
using namespace std;

int N, K;
char dp[31][31][31][451], result[31];

bool abc(int a, int b, int c, int k, int pos){
	char &ret = dp[a][b][c][k];
	if(ret != -1) return ret;
	if(pos == N) return ret = !k;

	if(abc(a+1, b, c, k, pos+1)){
		result[pos] = 'A';
		return ret = true;
	}
	if(abc(a, b+1, c, k-a, pos+1)){
		result[pos] = 'B';
		return ret = true;
	}
	if(abc(a, b, c+1, k-a-b, pos+1)){
		result[pos] = 'C';
		return ret = true;
	}
	return ret = false;
}

int main(){
	scanf("%d %d", &N, &K);
	memset(dp, -1, sizeof(dp));
	puts(abc(0, 0, 0, K, 0) ? result : "-1");
}