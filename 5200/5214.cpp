#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main(){
	int N, K, M;
	vector<int> adj[101000];
	scanf("%d %d %d", &N, &K, &M);
	for(int i=0; i<M; i++){
		for(int j=0; j<K; j++){
			int H;
			scanf("%d", &H);
			H--;
			adj[H].push_back(100000+i);
			adj[100000+i].push_back(H);
		}
	}

	bool visited[101000] = {1,};
	queue<int> Q;
	Q.push(0);
	for(int result=1; !Q.empty(); result++){
		if(visited[N-1]){
			printf("%d\n", result/2+1);
			return 0;
		}
		int qSize = Q.size();
		for(int i=0; i<qSize; i++){
			int curr = Q.front(); Q.pop();
			for(int next: adj[curr]){
				if(!visited[next]){
					visited[next] = true;
					Q.push(next);
				}
			}
		}
	}
	puts("-1");
}