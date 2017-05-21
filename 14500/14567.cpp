#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main(){
	int N, M, deg[1000] = {0}, result[1000] = {0};
	vector<int> adj[1000];
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		int A, B;
		scanf("%d %d", &A, &B);
		A--; B--;
		adj[A].push_back(B);
		deg[B]++;
	}

	queue<int> Q;
	for(int i=0; i<N; i++){
		if(deg[i] == 0){
			result[i] = 1;
			Q.push(i);
		}
	}
	for(int i=2; !Q.empty(); i++){
		int qSize = Q.size();
		for(int j=0; j<qSize; j++){
			int curr = Q.front();
			Q.pop();
			for(int next: adj[curr]){
				if(result[next]) continue;
				if(--deg[next] == 0){
					result[next] = i;
					Q.push(next);
				}
			}
		}
	}
	for(int i=0; i<N; i++)
		printf("%d ", result[i]);
}