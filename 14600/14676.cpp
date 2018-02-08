#include <cstdio>
#include <vector>
using namespace std;

int main(){
	int N, M, K;
	vector<int> adj[100000];
	int built[100000] = {0}, cnt[100000] = {0}, dest[100000] = {0};
	scanf("%d %d %d", &N, &M, &K);
	for(int i=0; i<M; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u-1].push_back(v-1);
		dest[v-1]++;
	}
	bool result = true;
	for(int i=0; i<K; i++){
		int t, u;
		scanf("%d %d", &t, &u);
		u--;
		if(!result) continue;

		if(t == 1){
			if(cnt[u] < dest[u]) result = false;
			else{
				if(built[u]++ == 0){
					for(int v: adj[u]) cnt[v]++;
				}
			}
		}
		else{
			if(!built[u]) result = false;
			else{
				if(--built[u] == 0){
					for(int v: adj[u]) cnt[v]--;
				}
			}
		}
	}
	puts(result ? "King-God-Emperor" : "Lier!");
}