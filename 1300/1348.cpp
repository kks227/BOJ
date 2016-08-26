#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 1000000000;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int N, M, A[100], B[100], dist[100][100], limit;
bool visited[100];

bool dfs(int a){
	visited[a] = true;
	for(int b=0; b<M; b++){
		if(dist[a][b] <= limit && (B[b] == -1 || !visited[B[b]] && dfs(B[b]))){
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}

int main(){
	int R, C;
	vector<int> car, park;
	char map[50][50];
	scanf("%d %d\n", &R, &C);
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			map[i][j] = getchar();
			if(map[i][j] == 'C') car.push_back(i*50+j);
			else if(map[i][j] == 'P') park.push_back(i*50+j);
		}
		getchar();
	}
	N = car.size();
	M = park.size();
	if(N > M){
		puts("-1");
		return 0;
	}
	if(N == 0){
		puts("0");
		return 0;
	}

	for(int i=0; i<N; i++){
		int d[50][50];
		for(int j=0; j<R; j++)
			fill(d[j], d[j]+C, INF);
		bool visited[50][50] = {0};
		queue<int> Q;

		d[car[i]/50][car[i]%50] = 0;
		visited[car[i]/50][car[i]%50] = true;
		Q.push(car[i]);
		while(!Q.empty()){
			int r = Q.front()/50;
			int c = Q.front()%50;
			Q.pop();
			for(int k=0; k<4; k++){
				int nr = r + roff[k];
				int nc = c + coff[k];
				if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
				if(visited[nr][nc] || map[nr][nc] == 'X') continue;
				visited[nr][nc] = true;
				d[nr][nc] = d[r][c] + 1;
				Q.push(nr*50+nc);
			}
		}

		for(int j=0; j<M; j++)
			dist[i][j] = d[park[j]/50][park[j]%50];
	}
	
	int match = 0;
	fill(A, A+N, -1);
	fill(B, B+M, -1);
	limit = INF - 1;
	for(int i=0; i<N; i++){
		if(A[i] == -1){
			fill(visited, visited+N, false);
			if(dfs(i)) match++;
		}
	}
	if(match != N){
		puts("-1");
		return 0;
	}

	int lo = 0, hi = R*C;
	while(lo+1 < hi){
		int mid = (lo+hi)/2;
		limit = mid;
		match = 0;
		fill(A, A+N, -1);
		fill(B, B+M, -1);
		for(int i=0; i<N; i++){
			if(A[i] == -1){
				fill(visited, visited+N, false);
				if(dfs(i)) match++;
			}
		}
		if(match == N) hi = mid;
		else lo = mid;
	}
	printf("%d\n", hi);
}