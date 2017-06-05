#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;

int main(){
	char N[8];
	int d1, d2;
	while(scanf("%s %d %d", N, &d1, &d2) > 0){
		int L = strlen(N), val = 0;
		for(int i=L-1, j=1; i>=0; i--, j*=d1)
			val += j * (N[i] - (isdigit(N[i]) ? '0' : 'A'-10));
		for(L=0; L<7 && val>0; L++){
			int k = val % d2;
			N[L] = k + (k < 10 ? '0' : 'A'-10);
			val /= d2;
		}
		if(val > 0) puts("  ERROR");
		else{
			for(int i=0; i<7-L; i++)
				putchar(' ');
			for(int i=L-1; i>=0; i--)
				putchar(N[i]);
			puts("");
		}
	}
}