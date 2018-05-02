#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;

int N, cost[100], dcnt, dfsn[100], result;
bool adj[100][100], finished[100];
stack<int> S;

int dfs(int curr){
	int ret = dfsn[curr] = ++dcnt;
	S.push(curr);
	for(int next=0; next<N; next++){
		if(!adj[curr][next]);
		else if(dfsn[next] == 0) ret = min(dfs(next), ret);
		else if(!finished[next]) ret = min(dfsn[next], ret);
	}
	if(ret == dfsn[curr]){
		int val = cost[curr];
		while(1){
			int temp = S.top(); S.pop();
			val = min(val, cost[temp]);
			finished[temp] = true;
			if(temp == curr) break;
		}
		result += val;
	}
	return ret;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", cost+i);
	for(int i=0; i<N; i++){
		getchar();
		for(int j=0; j<N; j++)
			adj[i][j] = (getchar() == '1');
	}
	for(int i=0; i<N; i++)
		if(dfsn[i] == 0) dfs(i);
	printf("%d\n", result);
}