#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 1<<17;

int main(){
	char W[MAX], S[MAX*2];
	scanf("%s %s", W, S);
	int M = strlen(S);
	copy(S, S+M-1, S+M);
	int N = M*2 - 1;
	int fail[MAX] = {0};
	for(int i=1, j=0; i<M; i++){
		while(j > 0 && W[i] != W[j]) j = fail[j-1];
		if(W[i] == W[j]) fail[i] = ++j;
	}

	int result = 0;
	for(int i=0, j=0; i<N; i++){
		while(j > 0 && S[i] != W[j]) j = fail[j-1];
		if(S[i] == W[j]){
			if(j == M-1){
				result++;
				j = fail[j];
			}
			else j++;
		}
	}
	printf("%d\n", result);
}