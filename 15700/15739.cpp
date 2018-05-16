#include <cstdio>
using namespace std;

int main(){
	int N, A[100][100], rSum[100] = {0}, cSum[100] = {0}, dSum[2] = {0}, M;
	bool result = true, used[10001] = {false,};
	scanf("%d", &N);
	M = N*(N*N+1)/2;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			scanf("%d", &A[i][j]);
			if(used[A[i][j]]) result = false;
			used[A[i][j]] = true;
			rSum[i] += A[i][j];
			cSum[j] += A[i][j];
			if(i == j) dSum[0] += A[i][j];
			if(i == N-j-1) dSum[1] += A[i][j];
		}
	}
	if(result){
		for(int i=0; i<N; i++)
			if(rSum[i] != M || cSum[i] != M) result = false;
		if(dSum[0] != M || dSum[1] != M) result = false;
	}
	puts(result ? "TRUE" : "FALSE");
}