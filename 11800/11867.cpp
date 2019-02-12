#include <cstdio>
#include <cstring>
using namespace std;

char dp[101][101];

bool game(int a, int b){
	char &ret = dp[a][b];
	if(ret != -1) return ret;
	if(a == 1 && b == 1) return ret = false;
	if(a > 1){
		for(int i = 1; i < a; ++i)
			if(!game(i, a-i)) return ret = true;
	}
	if(b > 1){
		for(int i = 1; i < b; ++i)
			if(!game(i, b-i)) return ret = true;
	}
	return ret = false;
}

int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	memset(dp, -1, sizeof(dp));
	puts(game(N, M) ? "A" : "B");
}