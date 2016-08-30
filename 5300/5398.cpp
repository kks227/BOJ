#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int A[500], B[500];
vector<int> adj[500];
bool visited[500];

bool dfs(int a){
	visited[a] = true;
	for(int b: adj[a]){
		if(B[b] == -1 || !visited[B[b]] && dfs(B[b])){
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int H, V, w[2000][2000];
		char map[2000][2000] = {0};
		scanf("%d %d", &H, &V);
		for(int i=0; i<H; i++){
			int x, y;
			char W[1001];
			scanf("%d %d %s", &x, &y, W);
			for(int j=0; W[j]; j++){
				map[y][x+j] = W[j];
				w[y][x+j] = i;
			}
			adj[i].clear();
		}
		for(int i=0; i<V; i++){
			int x, y;
			char W[1001];
			scanf("%d %d %s", &x, &y, W);
			for(int j=0; W[j]; j++){
				if(map[y+j][x] && map[y+j][x] != W[j])
					adj[w[y+j][x]].push_back(i);
			}
		}

		int result = H+V;
		fill(A, A+500, -1);
		fill(B, B+500, -1);
		for(int i=0; i<H; i++){
			if(A[i] == -1){
				fill(visited, visited+500, false);
				if(dfs(i)) result--;
			}
		}
		printf("%d\n", result);
	}
}