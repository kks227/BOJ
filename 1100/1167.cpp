#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> intPair;

int V, diameter = 0;
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
	scanf("%d", &V);
	for(int i=0; i<V; i++){
		int a, b, w;
		scanf("%d", &a);
		while(scanf("%d", &b)){
			if(b == -1) break;
			scanf("%d", &w);
			adj[a-1].push_back(intPair(b-1, w));
			if(maxDegree < adj[a-1].size()){
				maxDegree = adj[a-1].size();
				root = a-1;
			}
		}
	}
	visited[root] = true;
	height(root);
	printf("%d\n", diameter);
}