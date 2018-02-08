#include <cstdio>
#include <cstring>
using namespace std;
const int MOD = 1000000007;

int main(){
	int N, rA, cA, rB, cB, rC = 0, cC = 0, A[50][50], B[50][50], C[50][50];
	bool impossible = false;
	scanf("%d", &N);
	scanf("%d %d", &rA, &cA);
	for(int i=0; i<rA; i++)
		for(int j=0; j<cA; j++)
			scanf("%d", &A[i][j]);
	for(int t=1; t<N; t++){
		scanf("%d %d", &rB, &cB);
		for(int i=0; i<rB; i++)
			for(int j=0; j<cB; j++)
				scanf("%d", &B[i][j]);
		if(cA != rB) impossible = true;
		if(impossible) continue;

		rC = rA; cC = cB;
		memset(C, 0, sizeof(C));
		for(int i=0; i<rC; i++)
			for(int j=0; j<cC; j++)
				for(int k=0; k<cA; k++)
					C[i][j] = (C[i][j] + 1LL*A[i][k]*B[k][j]) % MOD;
		rA = rC; cA = cC;
		memcpy(A, C, sizeof(A));
	}
	if(impossible) puts("-1");
	else{
		int result = 0;
		for(int i=0; i<rA; i++)
			for(int j=0; j<cA; j++)
				result = (result + A[i][j]) % MOD;
		printf("%d\n", result);
	}
}