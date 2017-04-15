#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int roff[4] = {-1, 0, 1, 0}; // N, E, S, W
const int coff[4] = {0, 1, 0, -1};
const int p2d[3][3] = {-1, 0, -1, 3, -1, 1, -1, 2, -1}; // pos to dir
const int N = 7;

int main(){
	while(1){
		int r1, c1, r2, c2;
		scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
		if(r1 == 0) break;
		r1--; c1--; r2--; c2--;

		bool adj[N][N][4] = {0};
		getchar();
		for(int i=0; i<N; i++){
			getchar();
			for(int k=0; k<3; k++){
				for(int j=0; j<N; j++){
					for(int l=0; l<3; l++){
						char c = getchar();
						if(p2d[k][l] != -1 && c != '.')
							adj[i][j][p2d[k][l]] = true;
					}
					getchar();
				}
			}
		}
		bool spare[4] = {0};
		getchar();
		for(int k=0; k<3; k++){
			for(int l=0; l<3; l++){
				char c = getchar();
				if(p2d[k][l] != -1 && c != '.')
					spare[p2d[k][l]] = true;
			}
			getchar();
		}

		bool result = false;
		for(int ro=0; ro<4; ro++){ // spare block rotation
			for(int hv=0; hv<2; hv++){ // horizontal or vertical
				for(int k=1; k<N; k+=2){ // row or column number
					for(int o=0; o<N; o+=N-1){ // which side
						int r[2] = {r1, r2}, c[2] = {c1, c2};
						bool map[N][N][4], impossible = false;
						memcpy(map, adj, sizeof(map));
						if(hv){ // one row
							if(o == 0){
								for(int c=N-1; c>0; c--)
									for(int d=0; d<4; d++)
										map[k][c][d] = map[k][c-1][d];
								for(int i=0; i<2; i++){
									if(r[i] == k){
										if(c[i] == N-1){
											if(i == 1) impossible = true;
											c[i] = 0;
										}
										else c[i]++;
									}
								}
							}
							else{
								for(int c=0; c<N-1; c++)
									for(int d=0; d<4; d++)
										map[k][c][d] = map[k][c+1][d];
								for(int i=0; i<2; i++){
									if(r[i] == k){
										if(c[i] == 0){
											if(i == 1) impossible = true;
											c[i] = N-1;
										}
										else c[i]--;
									}
								}
							}
							for(int d=0; d<4; d++)
								map[k][o][d] = spare[(d+ro)%4];
						}
						else{ // one column
							if(o == 0){
								for(int r=N-1; r>0; r--)
									for(int d=0; d<4; d++)
										map[r][k][d] = map[r-1][k][d];
								for(int i=0; i<2; i++){
									if(c[i] == k){
										if(r[i] == N-1){
											if(i == 1) impossible = true;
											r[i] = 0;
										}
										else r[i]++;
									}
								}
							}
							else{
								for(int r=0; r<N-1; r++)
									for(int d=0; d<4; d++)
										map[r][k][d] = map[r+1][k][d];
								for(int i=0; i<2; i++){
									if(c[i] == k){
										if(r[i] == 0){
											if(i == 1) impossible = true;
											r[i] = N-1;
										}
										else r[i]--;
									}
								}
							}
							for(int d=0; d<4; d++)
								map[o][k][d] = spare[(d+ro)%4];
						}
						if(impossible) continue;

						bool visited[N][N] = {0};
						visited[r[0]][c[0]] = true;
						queue<int> Q;
						Q.push(r[0]*10+c[0]);
						while(!Q.empty()){
							int r = Q.front()/10, c = Q.front()%10;
							Q.pop();
							for(int d=0; d<4; d++){
								if(!map[r][c][d]) continue;
								int nr = r+roff[d], nc = c+coff[d];
								if(nr < 0 || nr >= N || nc < 0 || nc >= N || !map[nr][nc][(d+2)%4] || visited[nr][nc]) continue;
								visited[nr][nc] = true;
								Q.push(nr*10+nc);
							}
						}
						result |= visited[r[1]][c[1]];
					}
				}
			}
		}
		puts(result ? "You can win in one move." : "Bad luck!");
	}
}