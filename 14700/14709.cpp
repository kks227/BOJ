#include <cstdio>
using namespace std;

int main(){
	int N;
	bool adj[6][6] = {0}, result = true;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		if(u%3 == 2 || v%3 == 2) result = false;
		else adj[u][v] = adj[v][u] = true;
	}
	if(!adj[1][3] || !adj[1][4] || !adj[3][4]) result = false;
	puts(result ? "Wa-pa-pa-pa-pa-pa-pow!" : "Woof-meow-tweet-squeek");
}