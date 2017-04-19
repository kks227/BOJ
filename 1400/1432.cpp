#include <cstdio>
#include <queue>
using namespace std;

int main(){
	int N, in[300] = {0}, result[300];
	bool adj[300][300];
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			scanf("%1d", &adj[i][j]);
			if(adj[i][j]) in[i]++;
		}
	}
	
	priority_queue<int> PQ;
	for(int i=0; i<N; i++)
		if(in[i] == 0) PQ.push(i);
	for(int i=N; i>0; i--){
		if(PQ.empty()){
			puts("-1");
			return 0;
		}
		int curr = PQ.top();
		PQ.pop();
		result[curr] = i;
		for(int next=0; next<N; next++)
			if(adj[next][curr] && --in[next] == 0) PQ.push(next);
	}
	for(int i=0; i<N; i++)
		printf("%d ", result[i]);
}