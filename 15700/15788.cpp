#include <cstdio>
using namespace std;

int main(){
	int N, r, c;
	long long A[500][500], S, Se;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		bool no0 = true;
		long long sum = 0;
		for(int j=0; j<N; j++){
			scanf("%lld", &A[i][j]);
			if(A[i][j] == 0){
				no0 = false;
				r = i;
				c = j;
			}
			sum += A[i][j];
		}
		if(no0) S = sum;
		else Se = sum;
	}
	
	A[r][c] = S-Se;
	bool result = true;
	long long s3 = 0, s4 = 0;
	for(int i=0; i<N; i++){
		long long s1 = 0, s2 = 0;
		s3 += A[i][i];
		s4 += A[i][N-i-1];
		for(int j=0; j<N; j++){
			s1 += A[i][j];
			s2 += A[j][i];
		}
		if(s1 != S || s2 != S) result = false;
	}
	if(s3 != S || s4 != S) result = false;
	printf("%lld\n", result ? A[r][c] : -1);
}