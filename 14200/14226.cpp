#include <cstdio>
#include <queue>
using namespace std;
const int MAX = 2001;

int main(){
	int S;
	scanf("%d", &S);
	bool visited[MAX][MAX] = {false};
	visited[1][0] = true;
	queue<int> Q;
	Q.push(MAX);
	for(int result=0; ; result++){
		int qSize = Q.size();
		for(int i=0; i<qSize; i++){
			int s = Q.front()/MAX, c = Q.front()%MAX; Q.pop();
			if(s == S){
				printf("%d\n", result);
				return 0;
			}

			if(!visited[s][s]){
				visited[s][s] = true;
				Q.push(s*MAX + s);
			}
			if(s+c < MAX && !visited[s+c][c]){
				visited[s+c][c] = true;
				Q.push((s+c)*MAX + c);
			}
			if(s > 0 && !visited[s-1][c]){
				visited[s-1][c] = true;
				Q.push((s-1)*MAX + c);
			}
		}
	}
}