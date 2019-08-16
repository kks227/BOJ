#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	while(1){
		int b, m, M = 0;
		char p[1001];
		scanf("%d", &b);
		if(b == 0) break;

		scanf("%s %d", p, &m);
		for(int i = 1; m > 0; i *= b, m /= 10)
			M += m%10 * i;
		int result = 0, L = strlen(p);
		for(int i = L-1, j = 1; i >= 0; --i, j = 1LL*j*b%M)
			result = (result + 1LL*j*(p[i]-'0')) % M;
		if(result == 0) puts("0");
		else{
			for(L = 0; result > 0; ++L, result /= b)
				p[L] = result % b + '0';
			for(int i = L-1; i >= 0; --i)
				putchar(p[i]);
			puts("");
		}
	}
}