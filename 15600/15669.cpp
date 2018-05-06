#include <cstdio>
#include <vector>
using namespace std;

int N, p[100000], lv[100000], cnt[2][100000];
bool visited[100000];
vector<int> adj[100000], c[100000];

void dfs(int curr, int depth){
	lv[curr] = depth;
	cnt[depth%2][curr]++;
	for(int next: adj[curr]){
		if(visited[next]) continue;
		visited[next] = true;
		c[curr].push_back(next);
		p[next] = curr;
		dfs(next, depth+1);
		cnt[depth%2][curr] += cnt[depth%2][next];
		cnt[!(depth%2)][curr] += cnt[!(depth%2)][next];
	}
}

int main(){
	int M;
	scanf("%d %d", &N, &M);
	for(int i=0; i<N-1; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	p[0] = -1;
	visited[0] = true;
	dfs(0, 0);

	for(int i=0; i<M; i++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		u--; v--;

		long long result = 0;

		int L = lv[u] % 2;
		if(p[v] == u){
			// case 1: u is red
			result += 1LL * (cnt[L][0] - cnt[L][v]) * cnt[w ? !L : L][v];
			// case 2: u is black
			result += 1LL * (cnt[!L][0] - cnt[!L][v]) * cnt[w ? L : !L][v];
		}
		else{
			// case 1: u is red
			result += 1LL * (cnt[w ? !L : L][0] - cnt[w ? !L : L][u]) * cnt[L][u];
			// case 2: u is black
			result += 1LL * (cnt[w ? L : !L][0] - cnt[w ? L : !L][u]) * cnt[!L][u];
		}

		printf("%lld\n", result);
	}
}