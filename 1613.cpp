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
		int a, b;
		scanf("%d %d", &a, &b);
		D[a-1][b-1] = 1;
	}
	for(int k=0; k<V; k++)
		for(int i=0; i<V; i++)
			for(int j=0; j<V; j++)
				D[i][j] = min(D[i][j], D[i][k]+D[k][j]);
	int S;
	scanf("%d", &S);
	for(int i=0; i<S; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		a--; b--;
		if(D[a][b]==INF && D[b][a]==INF) puts("0");
		else if(D[a][b]!=INF && D[a][b]>0) puts("-1");
		else puts("1");
	}
}