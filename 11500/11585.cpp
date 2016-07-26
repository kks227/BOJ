#include <cstdio>
using namespace std;

inline int gcd(int p, int q){
	while(q){
		int r = p % q;
		p = q;
		q = r;
	}
	return p;
}

int main(){
	int N;
	scanf("%d", &N);
	char A[2000000], B[1000000];
	for(int i=0; i<N; i++){
		scanf(" %c", A+i);
		A[N+i] = A[i];
	}
	for(int i=0; i<N; i++)
		scanf(" %c", B+i);

	int pi[1000000] = {0}, j = 0;
	for(int i=1; i<N; i++){
		while(j > 0 && B[i] != B[j]) j = pi[j-1];
		if(B[i] == B[j]) pi[i] = ++j;
	}

	int cnt = 0;
	j = 0;
	for(int i=0; i<N*2-1; i++){
		while(j > 0 && A[i] != B[j]) j = pi[j-1];
		if(A[i] == B[j]){
			if(j == N-1){
				cnt++;
				j = pi[j];
			}
			else j++;
		}
	}

	int temp = gcd(N, cnt);
	printf("%d/%d\n", cnt/temp, N/temp);
}