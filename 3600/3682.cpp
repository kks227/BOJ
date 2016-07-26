#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int N, M, cnt, dfsn[20000], S, sn[20000];
vector<int> adj[20000];
bool finished[20000];
stack<int> ST;

int CompressByDFS(int curr){
	dfsn[curr] = ++cnt;
	ST.push(curr);
	int result = dfsn[curr];
	for(int next: adj[curr]){
		if(dfsn[next] == 0) result = min(result, CompressByDFS(next));
		else if(!finished[next]) result = min(result, dfsn[next]);
	}
	if(result >= dfsn[curr]){
		while(1){
			int n = ST.top();
			ST.pop();
			finished[n] = true;
			sn[n] = S;
			if(n == curr) break;
		}
		S++;
	}
	return result;
}



int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		scanf("%d %d", &N, &M);
		for(int i=0; i<N; i++)
			adj[i].clear();
		for(int i=0; i<M; i++){
			int A, B;
			scanf("%d %d", &A, &B);
			adj[A-1].push_back(B-1);
		}
		S = cnt = 0;
		memset(dfsn, 0, sizeof(dfsn));
		memset(sn, 0, sizeof(sn));
		memset(finished, 0, sizeof(finished));
		for(int i=0; i<N; i++)
			if(dfsn[i] == 0) CompressByDFS(i);
		if(S == 1){
			puts("0");
			continue;
		}

		vector<int> sIn(S, 0), sOut(S, 0);
		for(int i=0; i<N; i++)
			for(int j: adj[i])
				if(sn[i] != sn[j]){
					sOut[sn[i]]++;
					sIn[sn[j]]++;
				}

		int in0cnt = 0, out0cnt = 0;
		for(int i=0; i<S; i++){
			if(sIn[i] == 0) in0cnt++;
			if(sOut[i] == 0) out0cnt++;
		}
		printf("%d\n", max(in0cnt, out0cnt));
	}
}