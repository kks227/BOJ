#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	char S[21];
	scanf("%s", S);
	int L = strlen(S);
	for(int i=0; i<L/2; i++){
		if(S[i] != S[L-i-1]){
			puts("false");
			return 0;
		}
	}
	puts("true");
}