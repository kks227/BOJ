#include <cstdio>
using namespace std;

int main(){
	for(int t=1; ; t++){
		char c, d;
		scanf("%c %c", &c, &d);
		if(c == '#') break;

		printf("Case %d\n", t);
		int N, cnt = 0;
		scanf("%d\n", &N);
		while(1){
			char e = getchar();
			if(e == '\n' && ++cnt == N) break;
			putchar(e==c||e==d||e+32==c||e+32==d ? '_' : e);
		}
		puts("\n");
	}
}