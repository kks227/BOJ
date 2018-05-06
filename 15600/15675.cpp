#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

inline int oppo(int n){ return n/2*2 + !(n%2); }

// variable: 0~999 row, 1000~1999 col
int dfsn[4000], dcnt, SN, sn[4000];
vector<int> adj[4000];
stack<int> S;
bool finished[4000];

int dfs(int curr){
	int result = dfsn[curr] = ++dcnt;
	S.push(curr);
	for(int next: adj[curr]){
		if(dfsn[next] < 0) result = min(result, dfs(next));
		else if(!finished[next]) result = min(result, dfsn[next]);
	}
	if(result == dfsn[curr]){
		while(true){
			int temp = S.top(); S.pop();
			sn[temp] = SN;
			finished[temp] = true;
			if(temp == curr) break;
		}
		SN++;
	}
	return result;
}

int main(){
	int R, C;
	scanf("%d %d", &R, &C);
	for(int i=0; i<R; i++){
		getchar();
		for(int j=0; j<C; j++){
			char c = getchar();
			int a, b;
			if(c == '*'){ // jewel
				// r xor c => (r or c) and (!r or !c)
				a = i*2 + 1; b = 2000+j*2 + 1;
				adj[oppo(a)].push_back(b);
				adj[oppo(b)].push_back(a);
				a = i*2; b = 2000+j*2;
				adj[oppo(a)].push_back(b);
				adj[oppo(b)].push_back(a);
			}
			else if(c == '#'){ // censor
				// r = c => (r or !c) and (!r or c)
				a = i*2 + 1; b = 2000+j*2;
				adj[oppo(b)].push_back(a);
				adj[b].push_back(oppo(a));
				a = i*2; b = 2000+j*2 + 1;
				adj[oppo(a)].push_back(b);
				adj[oppo(b)].push_back(a);
			}
		}
	}

	fill(dfsn, dfsn+4000, -1);
	for(int i=0; i<4000; i++)
		if(dfsn[i] < 0) dfs(i);

	int result = 1;
	for(int i=0; i<2000; i++){
		if(sn[i*2] == sn[i*2+1]){
			result = 0;
			break;
		}
	}
	printf("%d\n", result);
}