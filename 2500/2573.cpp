#include <cstdio>
#include <cstring>
using namespace std;

int N, M, map[300][300], remain, offset[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
bool visited[300][300];

bool invalid(int r, int c){
	return r<0 || r>=N || c<0 || c>=M;
}

int DFS(int r, int c){
	if(visited[r][c] || !map[r][c]) return 0;
	visited[r][c] = true;
	int result = 1;
	for(int k=0; k<4; k++){
		int nextR = r+offset[k][0];
		int nextC = c+offset[k][1];
		if(invalid(nextR, nextC)) continue;
		result += DFS(nextR, nextC);
	}
	return result;
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++){
			scanf("%d", &map[i][j]);
			remain += (map[i][j]>0);
		}
	int result = 0;
	while(1){
		memset(visited, 0, sizeof(visited));
		int iceberg = 0;
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++)
				if(map[i][j]){
					iceberg = DFS(i, j);
					break;
				}
			if(iceberg) break;
		}
		if(iceberg != remain){
			printf("%d\n", result);
			break;
		}
		result++;
		int minus[300][300] = {0};
		for(int i=1; i<N-1; i++){
			for(int j=1; j<M-1; j++){
				if(map[i][j]==0) continue;
				for(int k=0; k<4; k++)
					minus[i][j] += !map[i+offset[k][0]][j+offset[k][1]];
			}
		}
		for(int i=1; i<N-1; i++){
			for(int j=1; j<M-1; j++){
				if(minus[i][j]==0) continue;
				map[i][j] -= minus[i][j];
				if(map[i][j] <= 0){
					map[i][j] = 0;
					remain--;
				}
			}
		}
		if(remain==0){
			puts("0");
			break;
		}
	}
}