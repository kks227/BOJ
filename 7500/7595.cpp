#include <cstdio>
using namespace std;

int main(){
	while(1){
		int N;
		scanf("%d", &N);
		if(N == 0) break;
		for(int i=0; i<N; i++){
			for(int j=0; j<=i; j++)
				putchar('*');
			puts("");
		}
	}
}