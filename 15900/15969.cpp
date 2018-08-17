#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, m = 1000, M = 0;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int A;
		scanf("%d", &A);
		m = min(m, A);
		M = max(M, A);
	}
	printf("%d\n", M-m);
}