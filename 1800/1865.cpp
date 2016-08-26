#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
const int INF = 1000000000;
typedef pair<int, int> P;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N, M, W;
		scanf("%d %d %d", &N, &M, &W);
		vector<P> in[500];
		for(int i=0; i<M; i++){
			int S, E, T;
			scanf("%d %d %d", &S, &E, &T);
			S--; E--;
			in[S].push_back(P(E, T));
			in[E].push_back(P(S, T));
		}
		for(int i=0; i<W; i++){
			int S, E, T;
			scanf("%d %d %d", &S, &E, &T);
			in[E-1].push_back(P(S-1, -T));
		}

		bool visited[500] = {0}, result = false;
		int dist[500];
		fill(dist, dist+N, INF);
		for(int i=0; i<N; i++){
			if(!visited[i]){
				visited[i] = true;
				dist[i] = 0;
				for(int k=0; k<N; k++){
					for(int j=0; j<N; j++){
						for(auto &p: in[j]){
							int prev = p.first, d = p.second;
							if(dist[j] > dist[prev] + d){
								visited[j] = true;
								dist[j] = dist[prev] + d;
								if(k == N-1) result = true;
							}
						}
					}
				}
			}
			if(result) break;
		}
		puts(result ? "YES" : "NO");
	}
}