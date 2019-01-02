#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

inline int d2(int x1, int y1, int x2, int y2){
	return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

int main(){
	int N, x[200], y[200], r[200];
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		scanf("%d %d %d", x+i, y+i, r+i);
	vector<int> adj[200];
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			if(i != j && d2(x[i], y[i], x[j], y[j]) <= r[i]*r[i]) adj[i].push_back(j);

	int result = 1;
	for(int i = 0; i < N; ++i){
		bool visited[200] = {false,};
		visited[i] = true;
		queue<int> Q;
		Q.push(i);
		int temp = 0;
		while(!Q.empty()){
			int curr = Q.front(); Q.pop();
			++temp;
			for(int next: adj[curr]){
				if(!visited[next]){
					visited[next] = true;
					Q.push(next);
				}
			}
		}
		result = max(temp, result);
	}
	printf("%d\n", result);
}