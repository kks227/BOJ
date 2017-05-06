#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
	int R, C, map[9][9];
	scanf("%d %d", &R, &C);
	for(int i=0; i<R; i++)
		for(int j=0; j<C; j++)
			scanf("%1d", &map[i][j]);

	int result = -1;
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			for(int k=-9; k<=9; k++){
				for(int l=-9; l<=9; l++){
					if(k == 0 && l == 0) continue;
					int N = 0, r = i, c = j;
					while(r >= 0 && r < R && c >= 0 && c < C){
						N = N*10 + map[r][c];
						if(abs(sqrt(N) - round(sqrt(N))) < 1e-6) result = max(result, N);
						r += k;
						c += l;
					}
				}
			}
		}
	}
	printf("%d\n", result);
}