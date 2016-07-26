#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
#include <functional>
using namespace std;

typedef pair<int, int> intPair;

int main(){
	int N, M;
	scanf("%d %d", &M, &N);
	bool map[100][100];
	for(int i=0; i<N; i++){
		getchar();
		for(int j=0; j<M; j++)
			map[i][j] = (getchar()=='1');
	}
	int offset[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
	bool visited[100][100] = {0};
	unsigned int dist[100][100];
	priority_queue<intPair, vector<intPair>, greater<intPair> > pq;
	pq.push(intPair(0, 0));
	memset(dist, 255, sizeof(dist));
	dist[0][0] = 0;
	for(int i=0; i<N*M-1; i++){
		int r, c;
		do{
			r = pq.top().second/100;
			c = pq.top().second%100;
			pq.pop();
		}while(visited[r][c]);
		visited[r][c] = true;
		for(int d=0; d<4; d++){
			int nextR = r + offset[d][0];
			int nextC = c + offset[d][1];
			if(nextR<0 || nextR>=N || nextC<0 || nextC>=M) continue;
			if(!visited[nextR][nextC] && dist[r][c]+map[nextR][nextC] < dist[nextR][nextC]){
				dist[nextR][nextC] = dist[r][c]+map[nextR][nextC];
				pq.push(intPair(dist[nextR][nextC], nextR*100+nextC));
			}
		}
	}
	printf("%d\n", dist[N-1][M-1]);
}