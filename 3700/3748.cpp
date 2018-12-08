#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 100000;
typedef pair<int, int> P;

int V, E, C, dcnt, dfsn[MAX], cRoot[MAX];
vector<int> adj[MAX];
set<int> cn[MAX];
stack<P> S;

int dfs(int curr, int prev = -1){
	int result = dfsn[curr] = dcnt++;
	for(int next: adj[curr]){
		if(next == prev) continue;

		if(dfsn[curr] > dfsn[next]) S.push(P(curr, next));
		if(dfsn[next] >= 0) result = min(result, dfsn[next]);
		else{
			int temp = dfs(next, curr);
			result = min(result, temp);
			if(temp >= dfsn[curr]){
				cRoot[C] = curr;
				while(!S.empty()){
					int u = S.top().first, v = S.top().second;
					S.pop();
					cn[u].insert(C);
					cn[v].insert(C);
					if(u == curr && v == next) break;
				}
				++C;
			}
		}
	}
	return result;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		scanf("%d %d", &V, &E);
		for(int i = 0; i < V; ++i){
			adj[i].clear();
			cn[i].clear();
		}
		for(int i = 0; i < E; ++i){
			int u, v;
			scanf("%d %d", &u, &v);
			--u; --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		C = dcnt = 0;
		fill(dfsn, dfsn+MAX, -1);
		for(int i = 0; i < V; ++i)
			if(dfsn[i] < 0) dfs(i);

		bool mark[MAX] = {false,};
		int depth[MAX] = {0,}, D = 1;
		for(int c = 0; c < C; ++c){
			int root = cRoot[c], d0 = D;
			vector<int> cv;
			queue<int> Q;
			cv.push_back(root);
			Q.push(root);
			depth[root] = D;

			bool flag = false;
			for(++D; !Q.empty(); ++D){
				int qSize = Q.size();
				for(int j = 0; j < qSize; ++j){
					int curr = Q.front(); Q.pop();

					for(int next: adj[curr]){
						if(cn[next].find(c) == cn[next].end()) continue;
						if(depth[next] < d0){
							cv.push_back(next);
							Q.push(next);
							depth[next] = D;
						}
						if(depth[curr] == depth[next]) flag = true;
					}
				}
			}
			if(!flag) continue;

			for(auto &v: cv)
				mark[v] = true;
		}

		int result = 0;
		for(int i = 0; i < V; ++i)
			if(mark[i]) ++result;
		printf("%d\n", result);
	}
}