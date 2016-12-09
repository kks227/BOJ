#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		char S[27];
		scanf("%s", S);
		int L = strlen(S);
		if(L%2){
			for(int i=0; i<L; i+=2) putchar(S[i]);
			for(int i=1; i<L; i+=2) putchar(S[i]);
			puts("");
			for(int i=1; i<L; i+=2) putchar(S[i]);
			for(int i=0; i<L; i+=2) putchar(S[i]);
			puts("");
		}
		else{
			for(int i=0; i<L; i+=2) putchar(S[i]);
			puts("");
			for(int i=1; i<L; i+=2) putchar(S[i]);
			puts("");
		}
	}
}