#include <cstdio>
using namespace std;
const int roff[3] = {-1, 0, 0};
const int coff[3] = {0, -1, 1};

int main(){
	int N;
	char map[1000][1000];
	scanf("%d\n", &N);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(i == 0) map[0][j] = getchar();
			else{
				int cnt = 0;
				for(int d=0; d<3; d++){
					int nr = i-1+roff[d], nc = j+coff[d];
					if(nr >= 0 && nc >= 0 && nc < N && map[nr][nc] == '#') cnt++;
				}
				map[i][j] = (cnt%2 ? '#' : '.');
			}
			putchar(map[i][j]);
		}
		puts("");
	}
}