#include <cstdio>
#include <queue>
using namespace std;

int main(){
	int N, S, E, A[10000];
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", A+i);
	scanf("%d %d", &S, &E);
	S--; E--;

	bool visited[10000] = {0};
	visited[S] = true;
	queue<int> Q;
	Q.push(S);
	for(int result = 0; !Q.empty(); result++){
		if(visited[E]){
			printf("%d\n", result);
			return 0;
		}

		int qSize = Q.size();
		for(int i=0; i<qSize; i++){
			int curr = Q.front();
			Q.pop();
			if(A[curr] == 0) continue;
			if(A[curr] < 0) A[curr] *= -1;
			for(int next=curr%A[curr]; next<N; next+=A[curr]){
				if(!visited[next]){
					visited[next] = true;
					Q.push(next);
				}
			}
		}
	}
	puts("-1");
}