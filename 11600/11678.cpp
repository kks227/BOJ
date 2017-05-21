#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
const int MAX = 52;

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
	int N;
	scanf("%d", &N);
	// 4i+1: player 1 has i, 4i+3: player 2 has i
	for(int i=0; i<26; i++){
		int p = i*4, q = i*4+2;
		adj[oppo(p)].push_back(q);
		adj[oppo(q)].push_back(p);
	}
	for(int i=0; i<N; i++){
		char a, b;
		int P, K;
		scanf(" %c%c %d %d", &a, &b, &P, &K);
		int A = (a-'A')*2, B = (b-'A')*2;
		P--;
		if(K == 0){
			int p = (A+P)*2, q = (B+P)*2;
			adj[oppo(p)].push_back(p);
			adj[oppo(q)].push_back(q);
		}
		else if(K == 1){
			int p = (A+P)*2 + 1, q = (B+P)*2 + 1;
			adj[oppo(p)].push_back(q);
			adj[oppo(q)].push_back(p);
			adj[p].push_back(oppo(q));
			adj[q].push_back(oppo(p));
		}
		else{
			int p = (A+P)*2 + 1, q = (B+P)*2 + 1;
			adj[oppo(p)].push_back(p);
			adj[oppo(q)].push_back(q);
		}
	}

	int result = 0;
	bool used[26] = {0};
	for(int a=0; a<26; a++){
		used[a] = true;
		for(int b=a+1; b<26; b++){
			used[b] = true;
			for(int c=b+1; c<26; c++){
				used[c] = true;
				for(int i=0; i<26; i++){
					int p = i*4, q = i*4+2;
					if(used[i]){
						adj[oppo(p)].push_back(p);
						adj[oppo(q)].push_back(q);
					}
					else{
						adj[oppo(p)].push_back(q);
						adj[oppo(q)].push_back(p);
						adj[p].push_back(oppo(q));
						adj[q].push_back(oppo(p));
					}
				}

				for(int i=0; i<MAX*2; i++)
					if(dfsn[i] == 0) dfs(i);
				bool possible = true;
				for(int i=0; i<MAX; i++){
					if(sn[i*2] == sn[i*2+1]){
						possible = false;
						break;
					}
				}
				if(possible) result++;

				for(int i=0; i<26; i++){
					int p = i*4, q = i*4+2;
					adj[oppo(p)].pop_back();
					adj[oppo(q)].pop_back();
					if(!used[i]){
						adj[p].pop_back();
						adj[q].pop_back();
					}
				}
				cnt = SN = 0;
				fill(dfsn, dfsn+MAX*2, 0);
				fill(finished, finished+MAX*2, 0);

				used[c] = false;
			}
			used[b] = false;
		}
		used[a] = false;
	}
	printf("%d\n", result);
}