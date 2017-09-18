#include <cstdio>
using namespace std;

int main(){
	int R, C;
	char map[50000][10];
	scanf("%d %d", &R, &C);
	for(int i=0; i<R; i++){
		getchar();
		for(int j=0; j<C; j++)
			map[i][j] = getchar();
	}
	for(int j=0; j<C; j++){
		int cnt = 0, s = 0;
		for(int i=0; i<R; i++){
			if(map[i][j] == '#'){
				for(int k=0; k<cnt; k++) map[i-k-1][j] = 'a';
				for(int k=i-cnt-1; k>=s; k--) map[k][j] = '.';
				cnt = 0;
				s = i+1;
			}
			else if(map[i][j] == 'a') cnt++;
		}
		for(int k=0; k<cnt; k++) map[R-k-1][j] = 'a';
		for(int k=R-cnt-1; k>=s; k--) map[k][j] = '.';
	}
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++)
			putchar(map[i][j]);
		puts("");
	}
}