#include <cstdio>
#include <queue>
using namespace std;

int main(){
	int S, G, F, U, D, result = 0;
	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
	S--; G--;
	bool visited[1000000] = {0};
	visited[S] = true;
	queue<int> Q;
	Q.push(S);
	while(!visited[G] && !Q.empty()){
		int qSize = Q.size();
		for(int i=0; i<qSize; i++){
			int c = Q.front();
			Q.pop();
			if(c+U < F && !visited[c+U]){
				visited[c+U] = true;
				Q.push(c+U);
			}
			if(c-D >= 0 && !visited[c-D]){
				visited[c-D] = true;
				Q.push(c-D);
			}
		}
		result++;
	}
	if(visited[G]) printf("%d\n", result);
	else puts("use the stairs");
}