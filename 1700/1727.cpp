#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int N, M, *A, *B, man[1000], woman[1000], dp[1000][1000];

int minDiff(int a, int b){
	if(a == N) return 0;
	int &ret = dp[a][b];
	if(ret != -1) return ret;

	ret = minDiff(a+1, b+1) + abs(A[a] - B[b]);
	if(N-a < M-b) ret = min(ret, minDiff(a, b+1));
	return ret;
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++)
		scanf("%d", man+i);
	for(int i=0; i<M; i++)
		scanf("%d", woman+i);
	sort(man, man+N);
	sort(woman, woman+M);
	A = man; B = woman;
	if(N > M){
		swap(N, M);
		swap(A, B);
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", minDiff(0, 0));
}