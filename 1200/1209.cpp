#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAX = 2000;

int N, A[MAX], B[MAX];
long long dp1[MAX+1][MAX], dp2[MAX+1][MAX];

long long seq1(int pos, int k){
	long long &ret = dp1[pos][k];
	if(ret != -1) return ret;
	if(pos == N) return ret = 0;
	ret = abs(A[pos]-B[k]) + seq1(pos+1, k);
	if(k < N-1) ret = min(seq1(pos, k+1), ret);
	return ret;
}

long long seq2(int pos, int k){
	long long &ret = dp2[pos][k];
	if(ret != -1) return ret;
	if(pos == N) return ret = 0;
	ret = abs(A[pos]-B[k]) + seq2(pos+1, k);
	if(k > 0) ret = min(seq2(pos, k-1), ret);
	return ret;
}

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%d", A+i);
		B[i] = A[i];
	}
	sort(B, B+N);
	memset(dp1, -1, sizeof(dp1));
	memset(dp2, -1, sizeof(dp2));
	printf("%lld\n", min(seq1(0, 0), seq2(0, N-1)));
}