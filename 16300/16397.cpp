#include <cstdio>
#include <queue>
using namespace std;

int main(){
	int N, T, G;
	scanf("%d %d %d", &N, &T, &G);
	queue<int> Q;
	bool visited[100000] = {false,};
	Q.push(N);
	visited[N] = true;
	for(int i = 0; ; ++i){
		if(visited[G]){
			printf("%d\n", i);
			return 0;
		}
		if(i == T) break;

		int qSize = Q.size();
		for(int j = 0; j < qSize; ++j){
			int curr = Q.front(); Q.pop();
			int next = curr+1;
			if(next < 100000 && !visited[next]){
				visited[next] = true;
				Q.push(next);
			}
			next = curr*2;
			if(next >= 100000) continue;
			int d = 1;
			while(d*10 <= next) d *= 10;
			next -= d;
			if(next > 0 && !visited[next]){
				visited[next] = true;
				Q.push(next);
			}
		}
	}
	puts("ANG");
}