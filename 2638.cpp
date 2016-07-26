#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int N, M, outCnt, offset[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
bool map[100][100], out[100][100];

bool invalid(int r, int c){
	return r<0 || r>=N || c<0 || c>=M;
}

void findOutside(){
	bool visited[100][100] = {0};
	queue<int> BFSQ;
	BFSQ.push(0);
	while(!BFSQ.empty()){
		int r = BFSQ.front()/100;
		int c = BFSQ.front()%100;
		BFSQ.pop();
		if(visited[r][c]) continue;
		if(!out[r][c]) outCnt++;
		visited[r][c] = out[r][c] = true;
		for(int i=0; i<4; i++){
			int nextR = r+offset[i][0];
			int nextC = c+offset[i][1];
			if(invalid(nextR, nextC)) continue;
			if(!map[nextR][nextC]) BFSQ.push(nextR*100+nextC);
		}
	}
}

void melt(){
	int erase[100][100] = {0};
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(!out[i][j]) continue;
			for(int k=0; k<4; k++){
				int nextR = i+offset[k][0];
				int nextC = j+offset[k][1];
				if(invalid(nextR, nextC)) continue;
				erase[nextR][nextC]++;
			}
		}
	}
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			if(map[i][j] && erase[i][j]>=2) map[i][j] = 0;
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++){
			int n;
			scanf("%d", &n);
			map[i][j] = (n==1);
		}
	int result = 0;
	while(1){
		findOutside();
		if(outCnt == N*M) break;
		result++;
		melt();
	}
	printf("%d\n", result);
}