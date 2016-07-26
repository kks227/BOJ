#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, K, A[5000000];
	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++)
		scanf("%d", A+i);
	nth_element(A, A+K-1, A+N);
	printf("%d\n", A[K-1]);
}