#include <cstdio>
using namespace std;

int main(){
	int N, K;
	scanf("%d", &N);
	char map[100][100];
	for(int i=0; i<N; i++){
		getchar();
		for(int j=0; j<N; j++)
			map[i][j] = getchar();
	}
	scanf("%d", &K);
	if(K == 1){
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++)
				putchar(map[i][j]);
			puts("");
		}
	}
	else if(K == 2){
		for(int i=0; i<N; i++){
			for(int j=N-1; j>=0; j--)
				putchar(map[i][j]);
			puts("");
		}
	}
	else{
		for(int i=N-1; i>=0; i--){
			for(int j=0; j<N; j++)
				putchar(map[i][j]);
			puts("");
		}
	}
}