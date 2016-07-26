#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 1000000000;

int main(){
	int V, E, D[400][400];
	scanf("%d %d", &V, &E);
	for(int i=0; i<V; i++)
		for(int j=0; j<V; j++)
			D[i][j] = INF;
	for(int i=0; i<E; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		D[a-1][b-1] = c;
	}
	for(int k=0; k<V; k++)
		for(int i=0; i<V; i++)
			for(int j=0; j<V; j++)
				D[i][j] = min(D[i][j], D[i][k]+D[k][j]);
	int result = INF;
	for(int i=0; i<V; i++)
		result = min(result, D[i][i]);
	printf("%d\n", result != INF ? result : -1);
}