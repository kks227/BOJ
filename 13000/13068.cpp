#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const double UNDEF = -1e9;
const double INF = 1e18;

struct Game{
	int A, L, P;
	Game(): Game(0, 0, 0){}
	Game(int A1, int L1, int P1): A(A1), L(L1), P(P1){}
	bool operator <(const Game& O)const{ return P*A*O.L*(100-O.P) > O.P*O.A*L*(100-P); }
};

int N, K, X;
Game G[100];
double dp[101][101];

double Funfair(int n, int k){
	double &ret = dp[n][k];
	if(ret != UNDEF) return ret;
	if(N-n < K-k) return ret = -INF;
	if(k == K) return ret = X;
	return ret = max(Funfair(n+1, k), Funfair(n+1, k+1)*( G[n].P*G[n].L/10000.0 - G[n].L/100.0 + 1 ) + G[n].P*G[n].A/100.0);
}

int main(){
	while(1){
		scanf("%d %d %d", &N, &K, &X);
		if(N == 0) break;

		for(int i = 0; i < N; ++i){
			scanf("%d %d %d", &G[i].A, &G[i].L, &G[i].P);
			fill(dp[i], dp[i]+N+1, UNDEF);
		}
		fill(dp[N], dp[N]+N+1, UNDEF);
		sort(G, G+N);
		printf("%.2lf\n", Funfair(0, 0));
	}
}