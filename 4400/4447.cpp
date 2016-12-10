#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d\n", &T);
	for(int t=0; t<T; t++){
		int c, g = 0, b = 0;
		while((c=getchar()) != '\n' && c >= 0){
			putchar(c);
			if(c >= 'a') c -= ('a'-'A');
			if(c == 'G') g++;
			else if(c == 'B') b++;
		}
		printf(" is %s\n", g==b ? "NEUTRAL" : g>b ? "GOOD" : "A BADDY");
	}
}