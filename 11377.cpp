#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int N, M, K, match1[2000], match2[1000];
vector<int> adj[2000];
bool visited[1000];

bool DFS(int a){
	for(int b: adj[a]){
		if(visited[b]) continue;
		visited[b] = true;
		if(match2[b]==-1 || DFS(match2[b])){
			match1[a] = b;
			match2[b] = a;
			return true;
		}
	}
	return false;
}

int main(){
	scanf("%d %d %d", &N, &M, &K);
	for(int i=0; i<N; i++){
		int works;
		scanf("%d", &works);
		for(int j=0; j<works; j++){
			int oppo;
			scanf("%d", &oppo);
			adj[i*2].push_back(oppo-1);
			adj[i*2+1].push_back(oppo-1);
		}
	}
	memset(match1, -1, sizeof(match1));
	memset(match2, -1, sizeof(match2));
	int result = 0;
	for(int i=0; i<N*2; i+=2){
		if(match1[i] == -1){
			memset(visited, 0, sizeof(visited));
			if(DFS(i)) result++;
		}
	}
	int over = 0;
	for(int i=1; i<N*2; i+=2){
		if(match1[i] == -1){
			memset(visited, 0, sizeof(visited));
			if(DFS(i)){
				result++;
				if(++over == K) break;
			}
		}
	}
	printf("%d\n", result);
}