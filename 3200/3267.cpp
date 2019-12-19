#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 100000;
typedef pair<int, int> intPair;

int diameter = 0;
vector<intPair> adj[MAX];
bool visited[MAX] = {0};

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
	int N, M, eSum = 0;
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N-1; ++i){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		--u; --v;
		adj[u].push_back(intPair(v, w));
		adj[v].push_back(intPair(u, w));
		eSum += w;
	}
	visited[0] = true;
	height(0);
	printf("%d\n", eSum*2 - diameter);
}