#include <cstdio>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;
typedef pair<int, int> intPair;

int N;
int offset[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};

bool invalid(int r, int c){
	return r<0 || r>=N || c<0 || c>=N;
}

int main(){
	bool map[50][50], visited[50][50]={0};
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		getchar();
		for(int j=0; j<N; j++)
			map[i][j] = (getchar()=='0');
	}
	int dist[50][50];
	memset(dist, 1, sizeof(dist));
	dist[0][0] = 0;
	priority_queue<intPair> pq;
	pq.push(intPair(0, 0));
	for(int i=0; i<N*N; i++){
		int r, c;
		do{
			r = pq.top().second/100;
			c = pq.top().second%100;
			pq.pop();
		}while(visited[r][c]);
		visited[r][c] = true;
		for(int k=0; k<4; k++){
			int nextR = r+offset[k][0];
			int nextC = c+offset[k][1];
			if(invalid(nextR, nextC)) continue;
			if(dist[nextR][nextC] >= dist[r][c]+map[nextR][nextC]){
				dist[nextR][nextC] = dist[r][c]+map[nextR][nextC];
				pq.push(intPair(-dist[nextR][nextC], nextR*100+nextC));
			}
		}
	}
	printf("%d\n", dist[N-1][N-1]);
}