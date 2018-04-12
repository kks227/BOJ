#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, A, B, C, D[100];
	scanf("%d %d %d %d", &N, &A, &B, &C);
	for(int i=0; i<N; i++)
		scanf("%d", D+i);
	sort(D, D+N);
	int cost = A, dsum = C;
	double result = 1.0*C/A;
	for(int i=0; i<N; i++){
		cost += B;
		dsum += D[N-i-1];
		result = max(1.0*dsum/cost, result);
	}
	printf("%d\n", (int)result);
}