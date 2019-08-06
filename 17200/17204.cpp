#include <cstdio>
using namespace std;
const int MAX = 150;

int main(){
	int N, K, go[MAX];
	bool visited[MAX] = {true,};
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N; ++i)
		scanf("%d", go+i);
	for(int i = 0, j = 1; ; ++j){
		if(visited[go[i]]){
			puts("-1");
			break;
		}
		if(go[i] == K){
			printf("%d\n", j);
			break;
		}
		i = go[i];
		visited[i] = true;
	}
}