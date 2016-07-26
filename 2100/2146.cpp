#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int N, cnt, A[100][100];
bool map[100][100], visited[100][100];
queue<int> Q;

inline bool invalid(int r, int c){
	return (r<0 || r>=N || c<0 || c>=N);
}

void DFS(int r, int c){
	visited[r][c] = true;
	A[r][c] = cnt;
	Q.push(r*100 + c);
	for(int d=0; d<4; d++){
		int nr = r+roff[d];
		int nc = c+coff[d];
		if(!invalid(nr, nc) && !visited[nr][nc] && map[nr][nc]) DFS(nr, nc);
	}
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			scanf("%d", &map[i][j]);
	
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			if(!visited[i][j] && map[i][j]){
				cnt++;
				DFS(i, j);
			}

	int result = 1;
	while(1){
		int qSize = Q.size();
		for(int i=0; i<qSize; i++){
			int r = Q.front()/100;
			int c = Q.front()%100;
			Q.pop();
			for(int d=0; d<4; d++){
				int nr = r+roff[d];
				int nc = c+coff[d];
				if(invalid(nr, nc)) continue;
				if(!visited[nr][nc]){
					visited[nr][nc] = true;
					A[nr][nc] = A[r][c];
					Q.push(nr*100 + nc);
				}
				else if(A[nr][nc] != A[r][c]){
					printf("%d\n", result);
					return 0;
				}
			}
		}

		result++;

		bool connected = false;
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				if(A[i][j] != 0)
					for(int d=0; d<4; d++){
						int nr = i+roff[d];
						int nc = j+coff[d];
						if(!invalid(nr, nc) && A[nr][nc]!=0 && A[nr][nc]!=A[i][j]){
							printf("%d\n", result);
							return 0;
						}
					}

		result++;
	}
}