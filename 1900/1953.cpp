#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main(){
	int N;
	vector<int> adj[100];
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int K;
		scanf("%d", &K);
		for(int j=0; j<K; j++){
			int val;
			scanf("%d", &val);
			adj[i].push_back(val-1);
		}
	}

	int cnt[2] = {0,};
	bool team[100] = {false,}, visited[100] = {false,};
	for(int i=0; i<N; i++){
		if(visited[i]) continue;

		cnt[0]++;
		visited[i] = true;
		queue<int> Q;
		Q.push(i);
		for(int t=true; !Q.empty(); t=!t){
			int qSize = Q.size();
			for(int j=0; j<qSize; j++){
				int curr = Q.front(); Q.pop();
				for(int next: adj[curr]){
					if(!visited[next]){
						visited[next] = true;
						team[next] = t;
						cnt[t]++;
						Q.push(next);
					}
				}
			}
		}
	}

	if(cnt[0] == N){
		cnt[0]--; cnt[1]++;
		team[0] = true;
	}
	for(int i=0; i<2; i++){
		printf("%d\n", cnt[i]);
		for(int j=0; j<N; j++)
			if(team[j] == i) printf("%d ", j+1);
		puts("");
	}
}