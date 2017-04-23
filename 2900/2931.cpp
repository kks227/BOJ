#include <cstdio>
using namespace std;
const int X = 1e9;
const int roff[4] = {-1, 0, 1, 0};
const int coff[4] = {0, 1, 0, -1};
const int d2c[7] = {'|', '-', '+', '1', '2', '3', '4'};
const int nr[4][7] = {
	{-1, X, -1, 0, X, X, 0},
	{X, 0, 0, X, X, -1, 1},
	{1, X, 1, X, 0, 0, X},
	{X, 0, 0, 1, -1, X, X}
};
const int nc[4][7] = {
	{0, X, 0, 1, X, X, -1},
	{X, 1, 1, X, X, 0, 0},
	{0, X, 0, X, 1, -1, X},
	{X, -1, -1, 0, 0, X, X}
};
const int nd[4][7] = {
	{0, X, 0, 1, X, X, 3},
	{X, 1, 1, X, X, 0, 2},
	{2, X, 2, X, 1, 3, X},
	{X, 3, 3, 2, 0, X, X}
};

int main(){
	int R, C, sr, sc, er, ec;
	char map[25][25];
	scanf("%d %d", &R, &C);
	int cnt = R*C;
	for(int i=0; i<R; i++){
		getchar();
		for(int j=0; j<C; j++){
			map[i][j] = getchar();
			switch(map[i][j]){
				case '|': map[i][j] = 0; break;
				case '-': map[i][j] = 1; break;
				case '+': map[i][j] = 2; cnt++; break;
				case '1': map[i][j] = 3; break;
				case '2': map[i][j] = 4; break;
				case '3': map[i][j] = 5; break;
				case '4': map[i][j] = 6; break;
				case 'M': sr = i; sc = j; break;
				case 'Z': er = i; ec = j; break;
				default: cnt--;
			}
		}
	}

	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			if(map[i][j] != '.') continue;

			for(int k=0; k<7; k++){
				map[i][j] = k;
				int temp = 0, r, c, d;
				for(int dd=0; dd<4; dd++){
					int rr = sr+roff[dd], cc = sc+coff[dd];
					if(rr < 0 || rr >= R || cc < 0 || cc >= C || map[rr][cc] == '.') continue;
					if(nd[dd][map[rr][cc]] != X){
						r = rr; c = cc; d = dd;
						temp++;
					}
				}
				if(temp != 1) continue;
				temp = 0;
				for(int dd=0; dd<4; dd++){
					int rr = er+roff[dd], cc = ec+coff[dd];
					if(rr < 0 || rr >= R || cc < 0 || cc >= C || map[rr][cc] == '.') continue;
					if(nd[dd][map[rr][cc]] != X) temp++;
				}
				if(temp != 1) continue;

				temp = 1;
				while(r != er || c != ec){
					temp++;
					if(map[r][c] == 'Z') break;

					int rr = r+nr[d][map[r][c]];
					int cc = c+nc[d][map[r][c]];
					int dd = nd[d][map[r][c]];
					if(rr < 0 || rr >= R || cc < 0 || cc >= C || map[rr][cc] == '.') break;
					if(map[rr][cc] != 'Z' && nd[dd][map[rr][cc]] == X) break;
					r = rr; c = cc; d = dd;
				}
				if(r == er && c == ec && cnt+(k==2) == temp){
					printf("%d %d %c\n", i+1, j+1, d2c[k]);
					return 0;
				}
			}
			map[i][j] = '.';
		}
	}
}