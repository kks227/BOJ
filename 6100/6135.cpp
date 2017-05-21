#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int main(){
	int N, M, T, d[300][300];
	scanf("%d %d %d", &N, &M, &T);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			d[i][j] = (i==j ? 0 : INF);
	for(int i=0; i<M; i++){
		int S, E, H;
		scanf("%d %d %d", &S, &E, &H);
		S--; E--;
		d[S][E] = min(d[S][E], H);
	}
	for(int k=0; k<N; k++)
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));
	for(int i=0; i<T; i++){
		int A, B;
		scanf("%d %d", &A, &B);
		A--; B--;
		printf("%d\n", d[A][B] < INF ? d[A][B] : -1);
	}
}