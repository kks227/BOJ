#include <cstdio>
#include <cmath>
using namespace std;
const int MAX = 1000;

int main(){
	int N, Q, A[MAX], pSum[MAX] = {0,};
	scanf("%d %d", &N, &Q);
	for(int i = 0; i < N; ++i){
		scanf("%d", A+i);
		if(i > 0) pSum[i] = pSum[i-1] + abs(A[i]-A[i-1]);
	}
	for(int i = 0; i < Q; ++i){
		int s, e;
		scanf("%d %d", &s, &e);
		printf("%d\n", pSum[e-1]-pSum[s-1]);
	}
}