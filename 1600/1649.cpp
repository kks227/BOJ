#include <cstdio>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int main(){
	int N, M, S, E, K, in[1000] = {0};
	set<int> C;
	vector<int> adj[1000];
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u-1].push_back(v-1);
		in[v-1]++;
	}
	scanf("%d %d %d", &S, &E, &K);
	S--; E--;
	for(int i=0; i<K; i++){
		int u;
		scanf("%d", &u);
		C.insert(u-1);
	}

	queue<int> Q;
	int val[1000] = {0}, cnt[1000] = {0};
	val[S] = 1;
	for(int i=0; i<N; i++)
		if(in[i] == 0) Q.push(i);
	while(!Q.empty()){
		int curr = Q.front();
		Q.pop();
		if(C.find(curr) != C.end()) cnt[curr]++;
		for(int next: adj[curr]){
			if(cnt[next] == cnt[curr]) val[next] += val[curr];
			else if(cnt[next] < cnt[curr]){
				cnt[next] = cnt[curr];
				val[next] = val[curr];
			}
			if(--in[next] == 0) Q.push(next);
		}
	}
	printf("%d\n", cnt[E] == C.size() ? val[E] : 0);
}