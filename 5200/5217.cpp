#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N;
		scanf("%d", &N);
		printf("Pairs for %d:", N);
		if(N > 2){
			printf(" %d %d", 1, N-1);
			for(int i=2; i<N-i; i++)
				printf(", %d %d", i, N-i);
		}
		puts("");
	}
}