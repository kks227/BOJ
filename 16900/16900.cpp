#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 500000;

int main(){
	int K;
	char S[MAX+1];
	scanf("%s %d", S, &K);
	int N = strlen(S);

	int p[MAX] = {0};
	for(int i = 1, j = 0; i < N; ++i){
		while(j > 0 && S[i] != S[j]) j = p[j-1];
		if(S[i] == S[j]) p[i] = ++j;
	}
	printf("%lld\n", N + 1LL*(K-1)*(N-p[N-1]));
}