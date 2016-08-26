#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const long long INF = 1LL<<60;

int main(){
	int N, M, S, E, R[100][100] = {0}, earn[100];
	scanf("%d %d %d %d", &N, &S, &E, &M);
	vector<P> adj[100];
	for(int i=0; i<M; i++){
		int A, B, C;
		scanf("%d %d %d", &A, &B, &C);
		adj[A].push_back(P(B, C));
		R[A][B] = 1;
	}
	for(int i=0; i<N; i++){
		scanf("%d", earn+i);
		R[i][i] = 1;
	}
	for(int k=0; k<N; k++)
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				if(R[i][k] && R[k][j]) R[i][j] = 1;

	bool Gee = false;
	long long dist[100];
	fill(dist, dist+N, INF);
	dist[S] = -earn[S];
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			for(auto &p: adj[j]){
				int next = p.first, d = p.second;
				if(dist[j] != INF && dist[next] > dist[j] + d - earn[next]){
					dist[next] = dist[j] + d - earn[next];
					if(i == N-1 && R[next][E]) Gee = true;
				}
			}
		}
	}
	if(Gee) puts("Gee");
	else if(dist[E] == INF) puts("gg");
	else printf("%lld\n", -dist[E]);
}