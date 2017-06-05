#include <cstdio>
#include <cctype>
#include <cstring>
using namespace std;

int main(){
	while(1){
		char S[11];
		scanf("%s", S);
		if(strcmp(S, "ENDOFINPUT") == 0) break;
		getchar();
		while(1){
			char c = getchar();
			putchar(isupper(c) ? (c-'A'+21)%26+'A' : c);
			if(c == '\n') break;
		}

		scanf("%s", S);
	}
}