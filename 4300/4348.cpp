#include <cstdio>
#include <cstring>
using namespace std;

int N, L[20], S;
char dp[1<<20];

char square(int used, int len, int finished){
	char &ret = dp[used];
	if(ret != -1) return ret;
	if(used == (1<<N)-1) return ret = true;

	ret = false;
	for(int i=0; i<N; i++){
		if(!(used & 1<<i)){
			if(len+L[i] > S/4) continue;
			ret |= square(used | 1<<i, (len+L[i]) % (S/4), finished + (len+L[i]==S/4));
		}
	}
	return ret;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		S = 0;
		scanf("%d", &N);
		for(int i=0; i<N; i++){
			scanf("%d", L+i);
			S += L[i];
		}
		if(S%4) puts("no");
		else{
			memset(dp, -1, sizeof(dp));
			puts(square(0, 0, 0) ? "yes" : "no");
		}
	}
}