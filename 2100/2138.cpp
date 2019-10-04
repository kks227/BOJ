#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 100000;
const int INF = 1e9;

int main(){
	int N, A[MAX], B[MAX], C[MAX], result = INF;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%1d", A+i);
		B[i] = A[i];
	}
	for(int i = 0; i < N; ++i)
		scanf("%1d", C+i);
	int temp = 0;
	for(int i = 0; i < N-1; ++i){
		if(A[i] == C[i]) continue;
		for(int j = 0; j < 3; ++j)
			A[i+j] = !A[i+j];
		++temp;
	}
	if(A[N-1] == C[N-1]) result = temp;
	temp = 1;
	B[0] = !B[0]; B[1] = !B[1];
	for(int i = 0; i < N-1; ++i){
		if(B[i] == C[i]) continue;
		for(int j = 0; j < 3; ++j)
			B[i+j] = !B[i+j];
		++temp;
	}
	if(B[N-1] == C[N-1]) result = min(temp, result);
	printf("%d\n", result == INF ? -1 : result);
}