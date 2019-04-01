#include <cstdio>
using namespace std;

int main(){
	while(1){
		char c;
		scanf("%c", &c);
		if(c == '#') break;
		int cnt = 0;
		while(1){
			char d = getchar();
			if(d == '\n') break;
			if(d == c || d == c - ('a'-'A')) ++cnt;
		}
		printf("%c %d\n", c, cnt);
	}
}