#include <cstdio>
using namespace std;

int main(){
	int N;
	scanf("%d\n", &N);
	for(int i=1; i<=N; i++){
		char S[51];
		gets(S);
		printf("%d. %s\n", i, S);
	}
}