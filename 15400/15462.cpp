#include <cstdio>
using namespace std;
const int MAX = 100000;

int N, next[MAX], result;
bool visited[MAX], finished[MAX];

void dfs(int curr){
	visited[curr] = true;
	if(!visited[next[curr]]) dfs(next[curr]);
	else if(!finished[next[curr]]){
		for(int i = next[curr]; i != curr; i = next[i])
			++result;
		++result;
	}
	finished[curr] = true;
}

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%d", next+i);
		--next[i];
	}
	for(int i = 0; i < N; ++i)
		if(!visited[i]) dfs(i);
	printf("%d\n", result);
}