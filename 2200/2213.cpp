#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int N, weight[10000], cache[10000][2];
vector<int> adj[10000], result;
bool visited[10000], selected[10000];

int maxSize(int root, bool canSelect){
	int &ret = cache[root][canSelect];
	if(ret != -1) return ret;
	visited[root] = true;
	int include = weight[root], exclude = 0;
	for(int next: adj[root])
		if(!visited[next]){
			include += maxSize(next, false);
			exclude += maxSize(next, true);
		}
	visited[root] = false;
	if(canSelect && include > exclude){
		selected[root] = true;
		return ret = include;
	}
	return ret = exclude;
}

void getNodes(int root, bool canSelect){
	visited[root] = true;
	if(canSelect && selected[root]){
		result.push_back(root);
		for(int next: adj[root])
			if(!visited[next]) getNodes(next, false);
	}
	else{
		for(int next: adj[root])
			if(!visited[next]) getNodes(next, true);
	}
	visited[root] = false;
}

int main(){
	scanf("%d", &N);
	memset(cache, -1, sizeof(cache));
	for(int i=0; i<N; i++)
		scanf("%d", weight+i);
	for(int i=0; i<N-1; i++){
		int U, V;
		scanf("%d %d", &U, &V);
		adj[U-1].push_back(V-1);
		adj[V-1].push_back(U-1);
	}
	printf("%d\n", maxSize(0, true));
	getNodes(0, true);
	sort(result.begin(), result.end());
	for(int node: result)
		printf("%d ", node+1);
}