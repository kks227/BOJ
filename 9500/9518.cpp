#include <cstdio>
#include <algorithm>
using namespace std;
int roff[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int coff[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main(){
	int R, C;
	char map[50][50];
	scanf("%d %d\n", &R, &C);
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++)
			map[i][j] = getchar();
		getchar();
	}

	int result = 0, m = 0;
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			int cnt = 0;
			for(int d=0; d<8; d++){
				int ni = i+roff[d], nj = j+coff[d];
				if(ni < 0 || ni >= R || nj < 0 || nj >= C || map[ni][nj] == '.') continue;
				cnt++;
			}
			if(map[i][j] == '.') m = max(m, cnt);
			else result += cnt;
		}
	}
	printf("%d\n", result/2 + m);
}