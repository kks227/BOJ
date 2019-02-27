#include <cstdio>
using namespace std;
const int N = 19;
const int roff[4] = {1, -1, 0, 1};
const int coff[4] = {0, 1, 1, 1};

int main(){
	int map[N][N] = {0,}, M, sr[100], sc[100];
	scanf("%d", &M);
	for(int i = 0; i < M; ++i)
		scanf("%d %d", sr+i, sc+i);

	for(int l = 0; l < M; ++l){
		map[sr[l]-1][sc[l]-1] = l%2 + 1;
		for(int j = 0; j < N; ++j){
			for(int i = 0; i < N; ++i){
				if(map[i][j] == 0) continue;
				for(int d = 0; d < 4; ++d){
					int r = i-roff[d], c = j-coff[d];
					if(r >= 0 && r < N && c >= 0 && c < N && map[r][c] == map[i][j]) continue;

					for(int k = 1; k < 6; ++k){
						r = i+roff[d]*k;
						c = j+coff[d]*k;
						if(r < 0 || r >= N || c < 0 || c >= N || map[r][c] != map[i][j]){
							if(k == 5){
								printf("%d\n", l+1);
								return 0;
							}
							break;
						}
					}
				}
			}
		}
	}
	puts("-1");
}