#include <cstdio>
using namespace std;
const int MAX = 500000;

int main(){
	int N, W, cnt = 0, adj[MAX] = {0,};
	scanf("%d %d", &N, &W);
	for(int i = 0; i < N-1; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		++adj[u-1];
		++adj[v-1];
	}
	if(adj[0] == 0) ++cnt;
	for(int i = 1; i < N; ++i)
		if(adj[i] == 1) ++cnt;
	printf("%.10lf\n", 1.0*W/cnt);
}