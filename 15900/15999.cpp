#include <cstdio>
using namespace std;
const int MOD = 1000000007;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int main(){
	int R, C;
	char map[2000][2000] = {0};
	scanf("%d %d", &R, &C);
	for(int i=0; i<R; i++){
		getchar();
		for(int j=0; j<C; j++)
			map[i][j] = getchar();
	}
	int result = 1;
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			bool flag = true;
			for(int d=0; d<4; d++){
				int nr = i+roff[d], nc = j+coff[d];
				if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
				if(map[i][j] != map[nr][nc]) flag = false;
			}
			if(flag) result = result*2 % MOD;
		}
	}
	printf("%d\n", result);
}