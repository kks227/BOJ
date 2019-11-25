#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAX = 300000;

int main(){
	int N, A[MAX];
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		scanf("%d", A+i);
	sort(A, A+N);
	int K = round(N*0.15), sum = 0;
	for(int i = K; i < N-K; ++i)
		sum += A[i];
	printf("%.0lf\n", N == 0 ? 0 : round(sum/(N-2.0*K)));
}