#include <cstdio>
#include <cstring>
using namespace std;

char dp[1001][2];
const int d[3] = {1, 3, 4};

char game(int n, bool turn){
	char &ret = dp[n][turn];
	if(ret != -1) return ret;
	if(n == 0) return ret = !turn;

	if(turn){
		ret = false;
		for(int i=0; i<3; i++)
			if(n >= d[i] && game(n-d[i], false)) ret = true;
	}
	else{
		ret = true;
		for(int i=0; i<3; i++)
			if(n >= d[i] && !game(n-d[i], true)) ret = false;
	}
	return ret;
}

int main(){
	int N;
	scanf("%d", &N);
	memset(dp, -1, sizeof(dp));
	printf("%s\n", game(N, true) ? "SK" : "CY");
}