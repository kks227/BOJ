#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 500000;

int main(){
	int N;
	long long A[MAX], B[MAX];
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		scanf("%lld", A+i);
	for(int i = 0; i < N; ++i)
		scanf("%lld", B+i);
	for(int i = 0; i < N; ++i)
		printf("%d ", upper_bound(B+i+1, B+N, A[i]) - (B+i+1));
}