#include <cstdio>
using namespace std;

int main(){
	char S[101];
	scanf("%s", S);
	for(int i=1; S[i]; i++){
		if(S[i-1] == S[i]){
			puts("Or not.");
			return 0;
		}
	}
	puts("Odd.");
}