#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		char S[11];
		scanf("%s", S);
		reverse(S, S+M);
		puts(S);
	}
}