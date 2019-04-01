#include <cstdio>
using namespace std;

int main(){
	while(1){
		int a, b;
		char c;
		scanf("%d %c %d", &a, &c, &b);
		if(a == 0 && b == 0 && c == 'W') break;
		if(c == 'W') b *= -1;
		if(a+b < -200) puts("Not allowed");
		else printf("%d\n", a+b);
	}
}