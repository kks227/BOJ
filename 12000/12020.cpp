#include <cstdio>
using namespace std;

double A[1000][1000], L[1000][1000] = {0}, U[1000][1000] = {0};

int main(){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			scanf("%lf", &A[i][j]);

	bool fail = false;
	for(int k=0; k<N; k++){
		L[k][k] = 1;
		if(k == 0) U[k][k] = A[k][k];
		else U[k][k] = A[k][k] - L[k][k-1] * U[k-1][k];
		if(U[k][k] == 0){
			fail = true;
			break;
		}
		if(k < N-1){
			U[k][k+1] = A[k][k+1];
			L[k+1][k] = A[k+1][k] / U[k][k];
		}
	}

	if(fail) puts("-1");
	else{
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++)
				printf("%.3lf ", L[i][j]);
			puts("");
		}
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++)
				printf("%.3lf ", U[i][j]);
			puts("");
		}
	}
}