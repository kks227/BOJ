#include <cstdio>
using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	if(N==1){
		puts("*");
		return 0;
	}
	for(int i=0; i<N*2; i++){
		if(i%2==0 && N%2) printf("* ");
		else if(i%2) putchar(' ');
		putchar('*');
		for(int j=1; j<N/2; j++) printf(" *");
		puts("");
	}
}