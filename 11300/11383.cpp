#include <cstdio>
using namespace std;

int main(){
	int N, M;
	char A[10][11], B[10][21];
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++)
		scanf("%s", A+i);
	for(int i=0; i<N; i++)
		scanf("%s", B+i);
	bool result = true;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++)
			if(A[i][j] != B[i][j*2] || A[i][j] != B[i][j*2+1]){
				result = false;
				break;
			}
		if(!result) break;
	}
	printf("%sEyfa\n", result?"":"Not ");
}