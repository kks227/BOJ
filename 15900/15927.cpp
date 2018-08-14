#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	char S[500001];
	scanf("%s", S);
	int L = strlen(S);

	bool flag = true;
	for(int i=0; i<L-1; i++)
		if(S[i] != S[i+1]) flag = false;
	if(flag){
		puts("-1");
		return 0;
	}

	for(int i=0; i<L/2; i++){
		if(S[i] != S[L-1-i]){
			printf("%d\n", L);
			return 0;
		}
	}
	printf("%d\n", L-1);
}