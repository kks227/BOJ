#include <cstdio>
using namespace std;
 
int main(){

	int N, M;
	char map[50][50];
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		getchar();
		for(int j=0; j<M; j++)
			map[i][j] = getchar();
	}

	int result = 0;
	for(int i=0; i<N-1; i++){
		for(int j=0; j<M-1; j++){
			for(int s=1; i+s<N; s++){
				if(j+s >= M) break;
				if(map[i][j] != map[i][j+s]) continue;
				if(map[i][j] != map[i+s][j]) continue;
				if(map[i][j] != map[i+s][j+s]) continue;
				if(s <= result) continue;
				result = s;
			}
		}
	}
	printf("%d\n", ++result*result);
 
    return 0;
}