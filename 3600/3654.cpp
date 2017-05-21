#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
const int roff[4] = {1, -1, 0, 0};
const int coff[4] = {0, 0, 1, -1};
const int MAX = 500000;

int cnt, SN, dfsn[MAX*2], sn[MAX*2];
vector<int> adj[MAX*2];
bool finished[MAX*2];
stack<int> S;

inline int oppo(int n){ return n%2 ? n-1 : n+1; }

int dfs(int curr){
	dfsn[curr] = ++cnt;
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
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int R, C, B = 0, W = 0, bn[500][500] = {0};
		char map[500][500];
		scanf("%d %d", &R, &C);
		for(int i=0; i<R; i++){
			getchar();
			for(int j=0; j<C; j++){
				map[i][j] = getchar();
				if(map[i][j] == 'B') bn[i][j] = B++;
				else if(map[i][j] == 'W') W++;
			}
		}
		if(B*2 != W){
			puts("NO");
			continue;
		}

		// 4i  : i-th black block is connected with above 
		// 4i+2: i-th black block is connected with left
		for(int i=0; i<R; i++){
			for(int j=0; j<C; j++){
				if(map[i][j] == 'B'){
					for(int d=0; d<4; d++){
						int ni = i+roff[d], nj = j+coff[d];
						if(ni >= 0 && ni < R && nj >= 0 && nj < C && map[ni][nj] == 'W') continue;
						int p = bn[i][j]*4 + oppo(d);
						adj[oppo(p)].push_back(p);
					}
				}
				else if(map[i][j] == 'W'){
					vector<int> a;
					for(int d=0; d<4; d++){
						int ni = i+roff[d], nj = j+coff[d];
						if(ni < 0 || ni >= R || nj < 0 || nj >= C || map[ni][nj] != 'B') continue;
						a.push_back(bn[ni][nj]*4 + d);
					}
					for(int k=0; k<a.size(); k++){
						int p = a[k];
						for(int l=k+1; l<a.size(); l++){
							int q = a[l];
							adj[oppo(p)].push_back(q);
							adj[oppo(q)].push_back(p);
						}
					}
				}
			}
		}

		for(int i=0; i<B*4; i++)
			if(dfsn[i] == 0) dfs(i);
		bool result = true;
		for(int i=0; i<B*2; i++){
			if(sn[i*2] == sn[i*2+1]){
				result = false;
				break;
			}
		}
		puts(result ? "YES" : "NO");

		cnt = SN = 0;
		fill(dfsn, dfsn+B*4, 0);
		fill(finished, finished+B*4, false);
		for(int i=0; i<B*4; i++)
			adj[i].clear();
	}
}