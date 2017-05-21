#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 2000;
typedef pair<int, int> P;

int dcnt, SN, dfsn[MAX*2], sn[MAX*2];
vector<int> adj[MAX*2];
bool finished[MAX*2];
stack<int> S;

inline int oppo(int n){ return n%2 ? n-1 : n+1; }

int dfs(int curr){
	dfsn[curr] = ++dcnt;
	S.push(curr);
	int result = dfsn[curr];
	for(int next: adj[curr]){
		if(dfsn[next] == 0) result = min(result, dfs(next));
		else if(!finished[next]) result = min(result, dfsn[next]);
	}
	if(result >= dfsn[curr]){
		sn[curr] = SN++;
		while(1){
			int family = S.top();
			S.pop();
			finished[family] = true;
			if(family == curr) break;
			sn[family] = sn[curr];
		}
	}
	return result;
}

int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	bool a[2000][2000] = {0};
	for(int i=0; i<M; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		x--; y--;
		a[x][y] = a[y][x] = true;
	}
	for(int i=0; i<2; i++){
		int p = i*2 + 1;
		a[i][i] = true;
		adj[oppo(p)].push_back(p);
	}
	for(int i=2; i<N; i++){
		int p = i*2 + 1;
		if(!a[i][0] && !a[i][1])
			adj[p].push_back(oppo(p));
		for(int j=2; j<N; j++){
			if(i == j) continue;
			if(!a[i][j]){
				int q = j*2 + 1;
				adj[oppo(p)].push_back(q);
				adj[oppo(q)].push_back(p);
				if(a[0][i] && a[0][j] || a[1][i] && a[1][j]){
					adj[p].push_back(oppo(q));
					adj[q].push_back(oppo(p));
				}
			}
		}
	}

	for(int i=0; i<N*2; i++)
		if(dfsn[i] == 0) dfs(i);
	bool possible = true;
	for(int i=0; i<N; i++){
		if(sn[i*2] == sn[i*2+1]){
			possible = false;
			break;
		}
	}
	if(!possible) puts("impossible");
	else{
		int result[MAX];
		fill(result, result+MAX, -1);
		P p[MAX*2];
		for(int i=0; i<N*2; i++)
			p[i] = P(sn[i], i);
		sort(p, p+N*2);
		for(int i=N*2-1; i>=0; i--){
			int val = p[i].second;
			if(result[val/2] == -1) result[val/2] = !(val%2);
		}
		for(int i=0; i<2; i++){
			for(int j=0; j<N; j++)
				if(a[i][j] && result[j]) printf("%d ", j+1);
			puts("");
		}
	}
}