#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
	int t[26] = {0}, d[26] = {0}, r[26] = {0}, result = 0;
	vector<int> adj[26];
	while(1){
		int u = getchar(), v;
		if(u < 0) break;
		u -= 'A';
		scanf("%d", t+u);
		while(1){
			v = getchar();
			if(v == '\n') break;
			if(v == ' ') continue;
			v -= 'A';
			adj[v].push_back(u);
			d[u]++;
		}
	}

	queue<int> Q;
	for(int i=0; i<26; i++)
		if(d[i] == 0) Q.push(i);
	while(!Q.empty()){
		int u = Q.front(); Q.pop();
		result = max(r[u]+=t[u], result);
		for(int v: adj[u]){
			r[v] = max(r[u], r[v]);
			if(--d[v] == 0) Q.push(v);
		}
	}
	printf("%d\n", result);
}