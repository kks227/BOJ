#include <cstdio>
#include <vector>
using namespace std;
const int INF = 1e9;

int main(){
	int N, M, dist[100][100], next[100][100];
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			dist[i][j] = (i == j ? 0 : INF);
			next[i][j] = -1;
		}
	}
	for(int i=0; i<M; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		a--; b--;
		if(dist[a][b] > c){
			dist[a][b] = c;
			next[a][b] = b;
		}
	}
	for(int k=0; k<N; k++){
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				if(dist[i][j] > dist[i][k] + dist[k][j]){
					dist[i][j] = dist[i][k] + dist[k][j];
					next[i][j] = next[i][k];
				}
			}
		}
	}
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++)
			printf("%d ", dist[i][j] < INF ? dist[i][j] : 0);
		puts("");
	}
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(i == j || dist[i][j] == INF){
				puts("0");
				continue;
			}
			vector<int> path(1, i);
			for(int k=i; k!=j;)
				path.push_back(k=next[k][j]);
			printf("%d", path.size());
			for(int k: path)
				printf(" %d", k+1);
			puts("");
		}
	}
}