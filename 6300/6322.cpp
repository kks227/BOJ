#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	for(int t=1; ; t++){
		int a[3];
		scanf("%d %d %d", a, a+1, a+2);
		if(a[0] == 0) break;

		printf("Triangle #%d\n", t);
		if(a[2] == -1) printf("c = %.3lf\n", sqrt(a[0]*a[0] + a[1]*a[1]));
		else{
			int i = (a[0] == -1 ? 0 : 1), j = !i;
			if(a[2]*a[2] <= a[j]*a[j]) puts("Impossible.");
			else printf("%c = %.3lf\n", 'a'+i, sqrt(a[2]*a[2] - a[j]*a[j]));
		}
		puts("");
	}
}