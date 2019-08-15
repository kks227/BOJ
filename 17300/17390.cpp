#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 300000;

int main(){
	int N, Q, A[MAX], pSum[MAX+1] = {0,};
	scanf("%d %d", &N, &Q);
	for(int i = 0; i < N; ++i)
		scanf("%d", A+i);
	sort(A, A+N);
	for(int i = 0; i < N; ++i)
		pSum[i+1] = pSum[i] + A[i];
	for(int i = 0; i < Q; ++i){
		int s, e;
		scanf("%d %d", &s, &e);
		printf("%d\n", pSum[e]-pSum[s-1]);
	}
}