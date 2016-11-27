#include <cstdio>
using namespace std;
const int roff[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int coff[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main(){
	while(1){
		int R, C;
		scanf("%d %d", &R, &C);
		if(R == 0) break;

		char map[100][100];
		for(int i=0; i<R; i++){
			getchar();
			for(int j=0; j<C; j++)
				map[i][j] = getchar();
		}
		for(int i=0; i<R; i++){
			for(int j=0; j<C; j++){
				if(map[i][j] == '*') continue;
				int cnt = 0;
				for(int k=0; k<8; k++){
					int ni = i+roff[k], nj = j+coff[k];
					if(ni<0 || ni>=R || nj<0 || nj>=C) continue;
					if(map[ni][nj] == '*') cnt++;
				}
				map[i][j] = cnt+'0';
			}
		}
		for(int i=0; i<R; i++){
			for(int j=0; j<C; j++)
				putchar(map[i][j]);
			puts("");
		}
	}
}