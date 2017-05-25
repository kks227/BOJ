#include <cstdio>
using namespace std;

int main(){
	int R, C;
	bool map[50][50];
	scanf("%d %d", &R, &C);
	for(int i=0; i<R; i++)
		for(int j=0; j<C; j++)
			scanf("%1d", &map[i][j]);
	for(int i=0; i<R; i++){
		for(int j=0, k; j<C; j++){
			scanf("%1d", &k);
			map[i][j] ^= k;
		}
	}
	int result = 0;
	for(int i=0; i<R-2; i++){
		for(int j=0; j<C-2; j++){
			if(!map[i][j]) continue;
			result++;
			for(int k=0; k<3; k++)
				for(int l=0; l<3; l++)
					map[i+k][j+l] = !map[i+k][j+l];
		}
	}
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			if(map[i][j]){
				puts("-1");
				return 0;
			}
		}
	}
	printf("%d\n", result);
}