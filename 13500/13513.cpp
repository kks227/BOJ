#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
#include <unordered_set>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 100000;
const int MAX_D = 18; // roundup log(2, 100000)
typedef pair<int, int> Edge;

class CentroidDecomposition{
public:
	void initialize(){
		scanf("%d", &N);
		for(int i = 0; i < N-1; ++i){
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			--u; --v;
			adj[u].push_back(Edge(v, w));
			adj[v].push_back(Edge(u, w));
			adjTemp[u].insert(v);
			adjTemp[v].insert(u);
		}

		memset(parent, -1, sizeof(parent));
		fill(depth, depth + N, -1);
		fill(dist, dist + N, -1);
		depth[0] = dist[0] = 0;
		queue<int> Q;
		Q.push(0);
		while(!Q.empty()){
			int curr = Q.front(); Q.pop();
			for(auto &e: adj[curr]){
				int next = e.first;
				if(depth[next] < 0){
					depth[next] = depth[curr] + 1;
					dist[next] = dist[curr] + e.second;
					parent[next][0] = curr;
					Q.push(next);
				}
			}
		}
		for(int j = 0; j < MAX_D-1; ++j)
			for(int i = 1; i < N; ++i)
				if(parent[i][j] != -1)
					parent[i][j+1] = parent[parent[i][j]][j];

		fill(cParent, cParent + N, -1);
		fill(sCnt, sCnt + N, 1);
		construct(0);

		whiteCnt = 0;
		fill(color, color + N, false);
		for(int i = 0; i < N; ++i)
			subtreeS[i].resize(sCnt[i]);
		for(int i = 0; i < N; ++i)
			update(i);
	}

	void update(int u){
		whiteCnt += (color[u] ? -1 : 1);
		color[u] = !color[u];
		int v = u, sIndex = 0;
		while(1){
			int d1 = getDist(u, v);
			auto &S1 = subtreeS[v][sIndex], &S2 = subtreeLongestS[v], &S3 = wholeS;

			int d2 = (S1.empty() ? -1 : *S1.rbegin());
			int d3 = getSubDiameter(v);
			if(d2 != -1) S2.erase(S2.find(d2));
			if(d3 != -1) S3.erase(S3.find(d3));

			if(color[u]) S1.insert(d1);
			else S1.erase(S1.find(d1));

			d2 = (S1.empty() ? -1 : *S1.rbegin());
			if(d2 != -1) S2.insert(d2);
			d3 = getSubDiameter(v);
			if(d3 != -1) S3.insert(d3);

			if(cParent[v] == -1) break;
			sIndex = cChildNum[v];
			v = cParent[v];
		}
	}

	int getFarthest(){
		if(whiteCnt == 0) return -1;
		if(whiteCnt == 1) return 0;
		return max(*wholeS.rbegin(), 0);
	}

private:
	int N, whiteCnt, parent[MAX][MAX_D], depth[MAX], dist[MAX], tSize[MAX], sCnt[MAX], cParent[MAX], cChildNum[MAX];
	vector<Edge> adj[MAX];
	unordered_set<int> adjTemp[MAX];
	bool color[MAX];
	vector<int> cChild[MAX];
	vector<multiset<int>> subtreeS[MAX]; // 0 is itself
	multiset<int> subtreeLongestS[MAX], wholeS;

	void construct(int curr, int prev = -1){
		int n = dfs1(curr);
		int root = dfs2(n, curr);
		if(prev == -1) cChildNum[root] = -1;
		else{
			cChildNum[root] = sCnt[prev]++;
			cChild[prev].push_back(root);
		}
		cParent[root] = prev;
		while(!adjTemp[root].empty()){
			int next = *adjTemp[root].begin();
			if(next != prev){
				adjTemp[root].erase(next);
				adjTemp[next].erase(root);
				construct(next, root);
			}
		}
	}

	int getLCA(int u, int v){
		if(depth[u] < depth[v]) swap(u, v);
		int diff = depth[u] - depth[v];
		for(int j = 0; diff > 0; ++j){
			if(diff % 2) u = parent[u][j];
			diff /= 2;
		}
		if(u != v){
			for(int j = MAX_D-1; j >= 0; --j){
				if(parent[u][j] != -1 && parent[u][j] != parent[v][j]){
					u = parent[u][j];
					v = parent[v][j];
				}
			}
			u = parent[u][0];
		}
		return u;
	}

	int getDist(int u, int v){
		int w = getLCA(u, v);
		return dist[u] + dist[v] - dist[w]*2;
	}

	int getSubDiameter(int u){
		auto &S = subtreeLongestS[u];
		if(S.size() < 2) return -1;
		auto rIter = S.rbegin();
		int d1 = *(rIter++);
		int d2 = *rIter;
		return d1 + d2;
	}

	int dfs1(int curr, int prev = -1){
		tSize[curr] = 1;
		for(int next: adjTemp[curr])
			if(next != prev) tSize[curr] += dfs1(next, curr);
		return tSize[curr];
	}

	int dfs2(int n, int curr, int prev = -1){
		for(int next: adjTemp[curr])
			if(next != prev && tSize[next] > n/2)
				return dfs2(n, next, curr);
		return curr;
	}
};

int main(){
	CentroidDecomposition CD;
	CD.initialize();
	int M;
	scanf("%d", &M);
	for(int i = 0; i < M; ++i){
		int o;
		scanf("%d", &o);
		if(o == 1){
			int u;
			scanf("%d", &u);
			CD.update(u-1);
		}
		else printf("%d\n", CD.getFarthest());
	}
}