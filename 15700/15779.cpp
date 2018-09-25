#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, A[5000];
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", A+i);

	int result = 1, dec = 0, inc = 0, s = 0;
	for(int e=1; e<N; e++){
		if(A[e-1] == A[e]){ inc++; dec++; }
		else if(A[e-1] < A[e]){ inc++; dec=0;}
		else{ dec++; inc=0; }
		if(inc >= 2 || dec >= 2) s = e-1;
		result = max(e-s+1, result);
	}
	printf("%d\n", result);
}