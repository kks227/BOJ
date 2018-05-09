#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, val[2][1000], dp[1001][1001];

int hexa(int a, int b){
	int &ret = dp[a][b];
	if(ret != -1) return ret;
	if(b == N) return ret = 0;

	int temp = 0;
	if(val[0][a] == val[1][b]) temp = 1;
	else if(val[0][a] > val[1][b]) temp = 2;
	return ret = max(hexa(a, b+1), hexa(a+1, b+1) + temp);
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<2; i++){
		for(int j=0; j<N; j++)
			scanf("%d", &val[i][j]);
		sort(val[i], val[i]+N);
		reverse(val[i], val[i]+N);
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", hexa(0, 0));
}