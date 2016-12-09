#include <cstdio>
#include <queue>
using namespace std;

int main(){
	int N, S, D, F, B, K;
	bool visited[100000] = {0};
	scanf("%d %d %d %d %d %d", &N, &S, &D, &F, &B, &K);
	S--; D--;
	for(int i=0; i<K; i++){
		int val;
		scanf("%d", &val);
		visited[val-1] = true;
	}

	queue<int> Q;
	Q.push(S);
	visited[S] = true;
	int result = 1;
	while(!Q.empty()){
		int qSize = Q.size();
		for(int i=0; i<qSize; i++){
			int curr = Q.front(), next;
			Q.pop();
			next = curr - B;
			if(next >= 0 && !visited[next]){
				Q.push(next);
				visited[next] = true;
			}
			next = curr + F;
			if(next < N && !visited[next]){
				Q.push(next);
				visited[next] = true;
			}
		}
		if(visited[D]) break;
		result++;
	}
	if(visited[D]) printf("%d\n", result);
	else puts("BUG FOUND");
}