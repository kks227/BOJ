#include <cstdio>
#include <cstring>
using namespace std;

int dp[32769][182][4];

int Lagrange(int n, int pos, int used){
	if(n == 0) return 1;
	if(used == 4 || pos == 182) return 0;
	int &ret = dp[n][pos][used];
	if(ret != -1) return ret;

	ret = Lagrange(n, pos+1, used);
	if(n >= pos*pos) ret += Lagrange(n-pos*pos, pos, used+1);
	return ret;
}

int main(){
	memset(dp, -1, sizeof(dp));
	while(1){
		int N;
		scanf("%d", &N);
		if(N == 0) break;
		printf("%d\n", Lagrange(N, 1, 0));
	}
}