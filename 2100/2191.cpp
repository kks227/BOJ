#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> adj;
vector<int> match1, match2;
vector<bool> visited;

bool DFS(int current){
	if(visited[current]) return false;
	visited[current] = true;
	for(int next: adj[current]){
		if(match2[next] == -1 || DFS(match2[next])){
			match1[current] = next;
			match2[next] = current;
			return true;
		}
	}
	return false;
}

int main(){
	int S, V;
	scanf("%d %d %d %d", &N, &M, &S, &V);
	int R[100][2], H[100][2];
	for(int i=0; i<N; i++){
		double R1, R2;
		scanf("%lf %lf", &R1, &R2);
		R[i][0] = R1*10.0+10e-9;
		R[i][1] = R2*10.0+10e-9;
	}
	for(int i=0; i<M; i++){
		double H1, H2;
		scanf("%lf %lf", &H1, &H2);
		H[i][0] = H1*10.0+10e-9;
		H[i][1] = H2*10.0+10e-9;
	}
	V *= 10;

	adj.resize(N);
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			if((R[i][0]-H[j][0])*(R[i][0]-H[j][0]) + (R[i][1]-H[j][1])*(R[i][1]-H[j][1]) <= 1LL*S*V*S*V)
				adj[i].push_back(j);

	match1.resize(N, -1);
	match2.resize(M, -1);
	int result = N;
	for(int i=0; i<N; i++){
		if(match1[i] != -1) continue;
		visited.clear();
		visited.resize(N, false);
		result -= DFS(i);
	}
	printf("%d\n", result);
}