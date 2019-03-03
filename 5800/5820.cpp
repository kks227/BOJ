#include <cstdio>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 200000;
const int MAX_K = 1000001;
const int INF = 1e9;
typedef pair<int, int> P;

int N, K, tSize[MAX];
vector<P> adj[MAX];
map<int, int> gMap[2]; // dist to depth
bool visited[MAX];

int getTreeSize(int curr, int prev = -1){
	tSize[curr] = 1;
	for(auto &p: adj[curr]){
		int next = p.first;
		if(next != prev && !visited[next]){
			getTreeSize(next, curr);
			tSize[curr] += tSize[next];
		}
	}
	return tSize[curr];
}

int getCentroid(int n, int curr, int prev = -1){
	for(auto &p: adj[curr]){
		int next = p.first;
		if(next != prev && !visited[next] && tSize[next] > n/2)
			return getCentroid(n, next, curr);
	}
	return curr;
}

void collectDistData(int dist, int depth, int curr, int prev = -1){
	if(dist > K) return;

	auto iter = gMap[1].find(dist);
	if(iter == gMap[1].end()) gMap[1][dist] = depth;
	else iter->second = min(iter->second, depth);

	for(auto &p: adj[curr]){
		int next = p.first, len = p.second;
		if(next != prev && !visited[next])
			collectDistData(dist + len, depth + 1, next, curr);
	}
}

int dc(int curr){
	int n = getTreeSize(curr);
	int root = getCentroid(n, curr);

	int result = INF;
	visited[root] = true;
	gMap[0][0] = 0;
	for(auto &p: adj[root]){
		int gRoot = p.first, len = p.second;
		if(visited[gRoot]) continue;

		collectDistData(len, 1, gRoot);
		for(auto &iter: gMap[1]){
			int p = iter.first, q = iter.second;
			auto iter2 = gMap[0].find(K - p);
			if(iter2 != gMap[0].end())
				result = min(q + iter2->second, result);
		}

		for(auto &iter: gMap[1]){
			int p = iter.first, q = iter.second;
			auto iter2 = gMap[0].find(p);
			if(iter2 != gMap[0].end())
				iter2->second = min(q, iter2->second);
			else gMap[0][p] = q;
		}
		gMap[1].clear();
	}
	gMap[0].clear();

	for(auto &p: adj[root]){
		int next = p.first;
		if(!visited[next]) result = min(dc(next), result);
	}
	return result;
}



int main(){
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N-1; ++i){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adj[u].push_back(P(v, w));
		adj[v].push_back(P(u, w));
	}

	fill(visited, visited+N, false);
	int result = dc(0);
	printf("%d\n", result == INF ? -1 : result);
}