#include <cstdio>
using namespace std;

int main(){
	while(1){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if(a == 0 && b == 0 && c == 0) break;
		if((c-a)%b != 0) puts("X");
		else printf("%d\n", (c-a)/b+1);
	}
}