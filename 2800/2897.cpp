#include <cstdio>
using namespace std;

int main(){
	int R, C, result[5] = {0};
	char map[50][50];
	scanf("%d %d", &R, &C);
	for(int i=0; i<R; i++){
		getchar();
		for(int j=0; j<C; j++)
			map[i][j] = getchar();
	}
	for(int i=0; i<R-1; i++){
		for(int j=0; j<C-1; j++){
			bool possible = true;
			int cnt = 0;
			for(int k=0; k<2; k++){
				for(int l=0; l<2; l++){
					if(map[i+k][j+l] == '#') possible = false;
					else if(map[i+k][j+l] == 'X') cnt++;
				}
			}
			if(possible) result[cnt]++;
		}
	}
	for(int i=0; i<5; i++)
		printf("%d\n", result[i]);
}