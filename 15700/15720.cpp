#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N[3], A[3][1000], cnt = 1000, r1 = 0, r2 = 0;
	scanf("%d %d %d", N, N+1, N+2);
	for(int i=0; i<3; i++){
		cnt = min(cnt, N[i]);
		for(int j=0; j<N[i]; j++)
			scanf("%d", &A[i][j]);
		sort(A[i], A[i]+N[i]);
		reverse(A[i], A[i]+N[i]);
	}
	for(int i=0; i<3; i++){
		for(int j=0; j<N[i]; j++){
			r1 += A[i][j];
			if(j < cnt) r2 += A[i][j]/10*9;
			else r2 += A[i][j];
		}
	}
	printf("%d\n%d\n", r1, r2);
}