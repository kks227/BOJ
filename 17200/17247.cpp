#include <cstdio>
#include <cmath>
using namespace std;
const int MAX = 1000;

int main(){
	int R, C, map[MAX][MAX], r[2], c[2], K = 0;
	scanf("%d %d", &R, &C);
	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j){
			scanf("%d", &map[i][j]);
			if(map[i][j] == 1){
				r[K] = i;
				c[K] = j;
				++K;
			}
		}
	}
	printf("%d\n", abs(r[0]-r[1]) + abs(c[0]-c[1]));
}