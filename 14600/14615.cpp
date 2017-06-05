#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main(){
	int N, M, T;
	vector<int> adj[100000][2];
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		int X, Y;
		scanf("%d %d", &X, &Y);
		X--; Y--;
		adj[X][0].push_back(Y);
		adj[Y][1].push_back(X);
	}
	bool visited[100000][2] = {0};
	visited[0][0] = visited[N-1][1] = true;
	for(int i=0; i<2; i++){
		queue<int> Q;
		Q.push(i ? N-1 : 0);
		while(!Q.empty()){
			int curr = Q.front(); Q.pop();
			for(int next: adj[curr][i]){
				if(!visited[next][i]){
					visited[next][i] = true;
					Q.push(next);
				}
			}
		}
	}
	scanf("%d", &T);
	for(int i=0; i<T; i++){
		int C;
		scanf("%d", &C);
		C--;
		puts(visited[C][0] && visited[C][1] ? "Defend the CTP" : "Destroyed the CTP");
	}
}