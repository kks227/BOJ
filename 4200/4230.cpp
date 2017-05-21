#include <cstdio>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 30;
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
	while(1){
		int N, M;
		scanf("%d %d", &N, &M);
		if(N == 0 && M == 0) break;

		// 2i: man is on Boram's side, 2i+1: Cheolseung
		adj[0].push_back(1);
		for(int i=0; i<M; i++){
			char s[2][10];
			scanf("%s %s", s, s+1);

			int n[2];
			bool b[2];
			for(int j=0; j<2; j++){
				char c;
				sscanf(s[j], "%d%c", n+j, &c);
				b[j] = (c == 'w');
			}
			int p = n[0]*2 + b[0], q = n[1]*2 + b[1];
			adj[oppo(p)].push_back(q);
			adj[oppo(q)].push_back(p);
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
		if(!possible) puts("bad luck");
		else{
            int result[MAX];
            P p[MAX*2];
            fill(result, result+N, -1);
            for(int i=0; i<N*2; i++)
				p[i] = P(sn[i], i);
			sort(p, p+N*2);
			for(int i=N*2-1; i>=0; i--){
				int val = p[i].second;
				if(result[val/2] == -1) result[val/2] = !(val%2);
			}
			for(int i=1; i<N; i++)
				printf("%d%c ", i, (result[i] ? 'w' : 'h'));
            puts("");
        }
        
        SN = dcnt = 0;
        fill(dfsn, dfsn+MAX*2, 0);
        fill(finished, finished+MAX*2, false);
        for(int i=0; i<N*2; i++)
            adj[i].clear();
    }
}