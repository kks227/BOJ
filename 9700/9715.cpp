#include <cstdio>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int R, C, map[52][52] = {0};
		scanf("%d %d", &R, &C);
		for(int i=1; i<=R; i++)
			for(int j=1; j<=C; j++)
				scanf("%1d", &map[i][j]);

		int result = 0;
		for(int i=0; i<=R+1; i++){
			for(int j=0; j<=C+1; j++){
				if(map[i][j] == 0) continue;
				result += 2;
				for(int d=0; d<4; d++){
					int ni = i+roff[d], nj = j+coff[d];
					if(map[i][j] > map[ni][nj]) result += map[i][j]-map[ni][nj];
				}
			}
		}
		printf("%d\n", result);
	}
}