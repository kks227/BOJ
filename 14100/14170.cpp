#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, Q, A[100000];
	scanf("%d %d", &N, &Q);
	for(int i = 0; i < N; ++i)
		scanf("%d", A+i);
	sort(A, A+N);
	for(int i = 0; i < Q; ++i){
		int s, e;
		scanf("%d %d", &s, &e);
		printf("%d\n", upper_bound(A, A+N, e) - lower_bound(A, A+N, s));
	}
}