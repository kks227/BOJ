#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 50;
const int INF = 1e9;

int main(){
	int N, M, K;
	bool know[MAX] = {false,}, in[MAX][MAX] = {false,}, visited[MAX] = {false,};
	scanf("%d %d %d", &N, &M, &K);
	for(int i = 0; i < K; ++i){
		int k;
		scanf("%d", &k);
		know[--k] = true;
	}
	queue<int> Q;
	vector<int> adj[MAX];
	for(int i = 0; i < M; ++i){
		int L;
		scanf("%d", &L);
		for(int j = 0; j < L; ++j){
			int k;
			scanf("%d", &k);
			in[i][--k] = true;
			if(know[k] && !visited[i]){
				visited[i] = true;
				Q.push(i);
			}
			for(int l = 0; l < i; ++l){
				if(in[l][k]){
					adj[l].push_back(i);
					adj[i].push_back(l);
				}
			}
		}
	}
	while(!Q.empty()){
		int curr = Q.front(); Q.pop();
		for(int next: adj[curr]){
			if(!visited[next]){
				visited[next] = true;
				Q.push(next);
			}
		}
	}
	int result = 0;
	for(int i = 0; i < M; ++i)
		if(!visited[i]) ++result;
	printf("%d\n", result);
}