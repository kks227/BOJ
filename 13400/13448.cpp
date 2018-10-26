#include <cstdio>
#include <algorithm>
using namespace std;
const long long UNDEF = -1e18;

struct Problem{
	int M, P, R;
	Problem(): Problem(0, 0, 0){}
	Problem(int M1, int P1, int R1): M(M1), P(P1), R(R1){}
	bool operator <(const Problem& O)const{ return 1LL*R*O.P < 1LL*P*O.R; }
};

int N, T;
Problem A[50];
long long dp[51][100001];

long long swTest(int pos, int t){
	long long &ret = dp[pos][t];
	if(ret != UNDEF) return ret;
	if(pos == N) return ret = 0;

	ret = swTest(pos+1, t);
	if(t+A[pos].R <= T)
		ret = max(swTest(pos+1, t+A[pos].R) + A[pos].M - 1LL*(t+A[pos].R)*A[pos].P, ret);
	return ret;
}

int main(){
	scanf("%d %d", &N, &T);
	for(int i = 0; i < N; ++i)
		scanf("%d", &A[i].M);
	for(int i = 0; i < N; ++i)
		scanf("%d", &A[i].P);
	for(int i = 0; i < N; ++i)
		scanf("%d", &A[i].R);
	sort(A, A+N);
	for(int i = 0; i <= N; ++i)
		fill(dp[i], dp[i]+T+1, UNDEF);
	printf("%lld\n", swTest(0, 0));
}