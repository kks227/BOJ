#include <cstdio>
#include <algorithm>
using namespace std;

int main(){

	int N, M;
	scanf("%d %d", &N, &M);
	int cnt2 = 0, cnt5 = 0;
	for(long long temp=2; temp<=N; temp*=2)
		cnt2 += N / temp;
	for(long long temp=2; temp<=M; temp*=2)
		cnt2 -= M / temp;
	for(long long temp=2; temp<=N-M; temp*=2)
		cnt2 -= (N-M) / temp;
	for(long long temp=5; temp<=N; temp*=5)
		cnt5 += N / temp;
	for(long long temp=5; temp<=M; temp*=5)
		cnt5 -= M / temp;
	for(long long temp=5; temp<=N-M; temp*=5)
		cnt5 -= (N-M) / temp;
	printf("%d\n", min(cnt2, cnt5));

	return 0;
}