#include <cstdio>
#include <cctype>
using namespace std;

inline int char2int(char c){
	if(isupper(c)) return c-'A'+10;
	return c-'0';
}

int main(){
	while(1){
		int c = getchar();
		if(c == -1) break;
		if(c == '\n') puts("");
		else{
			char d = getchar();
			putchar(char2int(c)*16 + char2int(d));
		}
	}
}