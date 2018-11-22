#include <cstdio>
#include <cstring>
using namespace std;

int L, N, AL[100];
char S[101], A[100][101], dp[101];

bool word(int pos){
	char &ret = dp[pos];
	if(ret != -1) return ret;
	if(pos == L) return ret = 1;

	ret = 0;
	for(int i = 0; i < N; ++i){
		if(L < pos+AL[i]) continue;
		bool flag = true;
		for(int j = 0; j < AL[i]; ++j)
			if(S[pos+j] != A[i][j]) flag = false;
		if(flag) ret |= word(pos+AL[i]);
	}
	return ret;
}

int main(){
	scanf("%s %d", S, &N);
	L = strlen(S);
	for(int i = 0; i < N; ++i){
		scanf("%s", A[i]);
		AL[i] = strlen(A[i]);
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", word(0));
}