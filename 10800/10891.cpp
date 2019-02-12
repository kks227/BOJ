#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <utility>
#include <unordered_set>
#include <algorithm>
using namespace std;
const int MAX_V = 100000;
const int MAX = MAX_V*2;
typedef pair<int, int> P;

int V, E, C, dcnt, dfsn[MAX_V], cSize[MAX];
vector<int> adj[MAX_V];
unordered_set<int> cMember[MAX];
stack<P> S;

int getBCC(int curr, int prev = -1){
	int result = dfsn[curr] = dcnt++;
	for(int next: adj[curr]){
		if(next == prev) continue;

		if(dfsn[curr] > dfsn[next]) S.push(P(curr, next));
		if(dfsn[next] >= 0) result = min(result, dfsn[next]);
		else{
			int temp = getBCC(next, curr);
			result = min(result, temp);
			if(temp >= dfsn[curr]){
				while(!S.empty()){
					int u = S.top().first, v = S.top().second;
					S.pop();
					cMember[C].insert(u);
					cMember[C].insert(v);
					++cSize[C];
					if(curr == u && next == v) break;
				}
				++C;
			}
		}
	}
	return result;
}

int main(){
	scanf("%d %d", &V, &E);
	for(int i = 0; i < E; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		--u; --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	fill(dfsn, dfsn+V, -1);
	getBCC(0);
	bool flag[MAX_V] = {false,};
	for(int i = 0; i < C; ++i){
		if(cMember[i].size() == 2) continue;
		if(cMember[i].size() != cSize[i]){
			puts("Not cactus");
			return 0;
		}
		for(int j: cMember[i]){
			if(flag[j]){
				puts("Not cactus");
				return 0;
			}
			flag[j] = true;
		}
	}
	puts("Cactus");
}