#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int M, N, cnt1, cnt2;
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
	scanf("%d %d", &M, &N);
	int map[100][100], V1[100][100], V2[100][100];
	memset(V1, -1, sizeof(V1));
	memset(V2, -1, sizeof(V2));
	for(int i=0; i<M; i++)
		for(int j=0; j<N; j++)
			scanf("%d", &map[i][j]);
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			if(map[i][j]) continue;
			if(V1[i][j] == -1){
				for(int k=0; i+k<M && map[i+k][j]!=2; k++)
					if(!map[i+k][j]) V1[i+k][j] = cnt1;
				cnt1++;
			}
			if(V2[i][j] == -1){
				for(int k=0; j+k<N && map[i][j+k]!=2; k++)
					if(!map[i][j+k]) V2[i][j+k] = cnt2;
				cnt2++;
			}
		}
	}
	adj.resize(cnt1);
	for(int i=0; i<M; i++)
		for(int j=0; j<N; j++)
			if(!map[i][j]) adj[V1[i][j]].push_back(V2[i][j]);
	match1.resize(cnt1, -1);
	match2.resize(cnt2, -1);
	int result = 0;
	for(int i=0; i<cnt1; i++){
		if(match1[i] != -1) continue;
		visited.clear();
		visited.resize(cnt1, false);
		result += DFS(i);
	}
	printf("%d\n", result);
}