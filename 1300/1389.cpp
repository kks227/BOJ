#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 1000000000;

int main(){
	int N, M, dist[100][100];
	for(int i=0; i<100; i++)
		for(int j=0; j<100; j++)
			dist[i][j] = (i==j ? 0 : INF);
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		int A, B;
		scanf("%d %d", &A, &B);
		A--; B--;
		dist[A][B] = dist[B][A] = 1;
	}
	for(int k=0; k<N; k++)
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
	int result = -1, minSum = INF;
	for(int i=0; i<N; i++){
		int sum = 0;
		for(int j=0; j<N; j++)
			if(i != j) sum += dist[i][j];
		if(sum < minSum){
			minSum = sum;
			result = i+1;
		}
	}
	printf("%d\n", result);
}