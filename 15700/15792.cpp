#include <cstdio>
using namespace std;

int main(){
	int A, B;
	scanf("%d %d", &A, &B);
	printf("%d", A/B);
	if(A%B){
		putchar('.');
		for(int i=0; i<=1000 && (A%=B); i++){
			A *= 10;
			printf("%1d", A/B);
		}
	}
	puts("");
}