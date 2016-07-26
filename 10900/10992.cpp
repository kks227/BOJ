#include <cstdio>
using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		for(int j=0; j<N-i-1; j++) putchar(' ');
		putchar('*');
		if(i==N-1)
			for(int j=0; j<i*2; j++) putchar('*');
		else if(i){
			for(int j=0; j<i*2-1; j++) putchar(' ');
			putchar('*');
		}
		puts("");
	}
}