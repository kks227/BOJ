#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> intPair;

int N, diameter = 0;
vector<intPair> adj[100000];
bool visited[100000] = {0};

int height(int node){
	visited[node] = true;
	if(adj[node].empty()) return 0;
	int fValue = 0, sValue = 0;
	for(auto& curr: adj[node]){
		if(visited[curr.first]) continue;
		int cValue = curr.second + height(curr.first);
		if(cValue > fValue){
			sValue = fValue;
			fValue = cValue;
		}
		else if(cValue > sValue) sValue = cValue;
	}
	diameter = max(diameter, fValue+sValue);
	return fValue;
}

int main(){
	int root = -1, maxDegree = 0;
	scanf("%d", &N);
	for(int i=0; i<N-1; i++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adj[u-1].push_back(intPair(v-1, w));
		adj[v-1].push_back(intPair(u-1, w));
		if(maxDegree < adj[u-1].size()){
			maxDegree = adj[u-1].size();
			root = u-1;
		}
		if(maxDegree < adj[v-1].size()){
			maxDegree = adj[v-1].size();
			root = v-1;
		}
	}
	visited[root] = true;
	height(root);
	printf("%d\n", diameter);
}