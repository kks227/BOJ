#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 1000001;
const int IMPOSSIBLE = 1e9;

int N, dp[MAX];
bool d[10];

inline bool valid(int n){
	while(n > 0){
		if(!d[n%10]) return false;
		n /= 10;
	}
	return true;
}

int game(int n){
	int &ret = dp[n];
	if(ret != -1) return ret;
	if(valid(n)) return 0;

	ret = IMPOSSIBLE;
	for(int i = 2; i*i <= n; ++i)
		if(n%i == 0) ret = min(game(i) + game(n/i) + 1, ret);
	return ret;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		scanf("%d", &N);
		fill(d, d+10, false);
		for(int i = 0; i < N; ++i){
			int j;
			scanf("%d", &j);
			d[j] = true;
		}
		fill(dp, dp+MAX, -1);
		int M;
		scanf("%d", &M);
		for(int i = 0; i < M; ++i){
			int K;
			scanf("%d", &K);
			int result = game(K);
			printf("%d\n", result == IMPOSSIBLE ? -1 : result);
		}
	}
}