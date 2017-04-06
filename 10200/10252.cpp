#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		puts("1");
		int M, N;
		scanf("%d %d", &M, &N);
		M--; N--;
		if(M%2){
			for(int i=0; i<=M; i++){
				if(i%2){
					for(int j=N; j>=0; j--)
						printf("(%d,%d)\n", i, j);
				}
				else{
					for(int j=0; j<=N; j++)
						printf("(%d,%d)\n", i, j);
				}
			}
		}
		else if(N%2){
			for(int j=0; j<=N; j++){
				if(j%2){
					for(int i=M; i>=0; i--)
						printf("(%d,%d)\n", i, j);
				}
				else{
					for(int i=0; i<=M; i++)
						printf("(%d,%d)\n", i, j);
				}
			}
		}
		else{
			for(int j=0; j<=N; j++)
				printf("(0,%d)\n", j);
			for(int j=N; j>=0; j--){
				if(j%2){
					for(int i=M; i>0; i--)
						printf("(%d,%d)\n", i, j);
				}
				else{
					for(int i=1; i<=M; i++)
						printf("(%d,%d)\n", i, j);
				}
			}
		}
	}
}