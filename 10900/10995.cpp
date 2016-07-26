#include <cstdio>
using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		if(i%2) putchar(' ');
		putchar('*');
		for(int j=1; j<N; j++) printf(" *");
		puts("");
	}
}