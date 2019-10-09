#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 800;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int main(){
	int N, S, sr, sc, er, ec;
	vector<int> hive;
	char map[MAX][MAX];
	scanf("%d %d", &N, &S);
	for(int i = 0; i < N; ++i){
		getchar();
		for(int j = 0; j < N; ++j){
			map[i][j] = getchar();
			if(map[i][j] == 'M'){ sr = i; sc = j; }
			else if(map[i][j] == 'D'){ er = i; ec = j; }
			else if(map[i][j] == 'H'){ hive.push_back(i*MAX + j); }
		}
	}

	int lo = -1, hi = N*N;
	while(lo+1 < hi){
		int mid = (lo+hi)/2;

		queue<int> Q1, Q2;
		bool visited1[MAX][MAX] = {false,}, visited2[MAX][MAX] = {false,};
		for(int i: hive){
			Q2.push(i);
			visited2[i/MAX][i%MAX] = true;
		}
		for(int i = 0; i < mid; ++i){
			int qSize = Q2.size();
			for(int j = 0; j < qSize; ++j){
				int r = Q2.front()/MAX, c = Q2.front()%MAX;
				Q2.pop();
				for(int d = 0; d < 4; ++d){
					int nr = r+roff[d], nc = c+coff[d];
					if(nr < 0 || nr >= N || nc < 0 || nc >= N || map[nr][nc] == 'T' || map[nr][nc] == 'D') continue;
					if(!visited2[nr][nc]){
						visited2[nr][nc] = true;
						Q2.push(nr*MAX + nc);
					}
				}
			}
		}

		bool flag = false;
		Q1.push(sr*MAX + sc);
		visited1[sr][sc] = true;
		while(!Q1.empty() && !flag){
			for(int i = 0; i < S && !flag; ++i){
				int qSize = Q1.size();
				for(int j = 0; j < qSize; ++j){
					int r = Q1.front()/MAX, c = Q1.front()%MAX;
					Q1.pop();
					if(visited2[r][c]) continue;
					if(r == er && c == ec){
						flag = true;
						break;
					}
					for(int d = 0; d < 4; ++d){
						int nr = r+roff[d], nc = c+coff[d];
						if(nr < 0 || nr >= N || nc < 0 || nc >= N || map[nr][nc] == 'T') continue;
						if(!visited2[nr][nc] && !visited1[nr][nc]){
							visited1[nr][nc] = true;
							Q1.push(nr*MAX + nc);
						}
					}
				}
			}
			int qSize = Q2.size();
			for(int j = 0; j < qSize; ++j){
				int r = Q2.front()/MAX, c = Q2.front()%MAX;
				Q2.pop();
				for(int d = 0; d < 4; ++d){
					int nr = r+roff[d], nc = c+coff[d];
					if(nr < 0 || nr >= N || nc < 0 || nc >= N || map[nr][nc] == 'T' || map[nr][nc] == 'D') continue;
					if(!visited2[nr][nc]){
						visited2[nr][nc] = true;
						Q2.push(nr*MAX + nc);
					}
				}
			}
		}

		(flag ? lo : hi) = mid;
	}
	printf("%d\n", lo);
}