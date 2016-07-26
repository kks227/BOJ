#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int cnt, dfsn[26];
vector<int> adj[26];
bool finished[26];
stack<int> S;
vector<vector<int>> scc;

int GetSCCsByDFS(int curr){
	dfsn[curr] = ++cnt;
	S.push(curr);
	int result = dfsn[curr];
	for(int next: adj[curr]){
		if(dfsn[next] == 0) result = min(result, GetSCCsByDFS(next));
		else if(!finished[next]) result = min(result, dfsn[next]);
	}
	if(result >= dfsn[curr]){
		vector<int> newScc;
		while(1){
			int t = S.top();
			S.pop();
			finished[t] = true;
			newScc.push_back(t);
			if(t == curr) break;
		}
		sort(newScc.begin(), newScc.end());
		scc.push_back(newScc);
	}
	return result;
}



int main(){
	while(1){
		int N;
		scanf("%d", &N);
		if(N == 0) break;

		bool exists[26] = {0};
		for(int i=0; i<26; i++)
			adj[i].clear();
		for(int i=0; i<N; i++){
			char post[5], pre;
			for(int j=0; j<5; j++)
				scanf(" %c", post+j);
			scanf(" %c", &pre);
			for(int j=0; j<5; j++){
				adj[pre-'A'].push_back(post[j]-'A');
				exists[post[j]-'A'] = true;
			}
			exists[pre-'A'] = true;
		}

		cnt = 0;
		memset(dfsn, 0, sizeof(dfsn));
		memset(finished, 0, sizeof(finished));
		scc.clear();
		for(int i=0; i<26; i++)
			if(exists[i] && dfsn[i] == 0) GetSCCsByDFS(i);
		sort(scc.begin(), scc.end());

		for(auto& v: scc){
			for(int n: v)
				printf("%c ", n+'A');
			puts("");
		}
		puts("");
	}
}