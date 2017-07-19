#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int MOD = 1000000007;

char W[10001], S[10001];
int M, N, dp[10001][4][3][2][2];
bool found[10000];

int find(int pos, int p, int q, int r, int s){
	int &ret = dp[pos][p][q][r][s];
	if(ret != -1) return ret;
	if(pos+M > N) return ret = (p == 3 && q == 2 && r && s);

	ret = find(pos+1, p, q, r, s);
	if(found[pos]){
		int k = pos + 1;
		int a[4] = {p, q, r, s}, b[4] = {2, 3, 5, 7}, c[4] = {3, 2, 1, 1};
		for(int i=0; i<4; i++){
			while(a[i] < c[i] && k%b[i] == 0){
				a[i]++;
				k /= b[i];
			}
		}
		ret += find(pos+1, a[0], a[1], a[2], a[3]);
	}
	return ret %= MOD;
}

int main(){
	scanf("%s %s", W, S);
	M = strlen(W);
	N = strlen(S);

	int p[10000] = {0};
	for(int i=1, j=0; i<M; i++){
		while(j > 0 && W[i] != W[j]) j = p[j-1];
		if(W[i] == W[j]) p[i] = ++j;
	}
	for(int i=0, j=0; i<N; i++){
		while(j > 0 && S[i] != W[j]) j = p[j-1];
		if(S[i] == W[j]){
			if(j == M-1){
				found[i-M+1] = true;
				j = p[j];
			}
			else j++;
		}
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", find(0, 0, 0, 0, 0));
}