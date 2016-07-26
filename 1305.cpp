#include <cstdio>
using namespace std;

int main(){
	int L;
	char S[1000001];
	scanf("%d %s", &L, S);

	int pi[1000000] = {0}, j = 0;
	for(int i=1; i<L; i++){
		while(j > 0 && S[i] != S[j]) j = pi[j-1];
		if(S[i] == S[j]) pi[i] = ++j;
	}
	printf("%d\n", pi[L-1]>0 ? L-pi[L-1] : L);
}