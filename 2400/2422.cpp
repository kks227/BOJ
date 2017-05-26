#include <cstdio>
using namespace std;

int main(){
	int N, M;
	bool adj[200][200] = {0};
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		u--; v--;
		adj[u][v] = adj[v][u] = true;
	}
	int result = 0;
	for(int i=0; i<N; i++){
		for(int j=i+1; j<N; j++){
			if(adj[i][j]) continue;
			for(int k=j+1; k<N; k++)
				if(!adj[i][k] && !adj[j][k]) result++;
		}
	}
	printf("%d\n", result);
}