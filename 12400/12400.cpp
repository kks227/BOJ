#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	char to[26] = {
		'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l',
		'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'
	};
	for(int t=1; ;){
		char c = getchar();
		if(c == '\n'){
			if(t > 1) puts("");
			if(t > T) break;
			printf("Case #%d: ", t++);
		}
		else if(c == ' ') putchar(' ');
		else putchar(to[c-'a']);
	}
}