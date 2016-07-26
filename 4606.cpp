#include <cstdio>
using namespace std;

int main(){
	while(1){
		char S[80];
		gets(S);
		if(S[0] == '#') break;
		for(int i=0; S[i]; i++){
			switch(S[i]){
			case ' ': printf("%%20"); break;
			case '!': printf("%%21"); break;
			case '$': printf("%%24"); break;
			case '%': printf("%%25"); break;
			case '(': printf("%%28"); break;
			case ')': printf("%%29"); break;
			case '*': printf("%%2a"); break;
			default: putchar(S[i]);
			}
		}
		puts("");
	}
}