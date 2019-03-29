#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 10001;

int main(){
	int N, P[MAX], dp[2][MAX] = {0,};
	scanf("%d", &N);
	for(int i = 0; i < N-1; ++i)
		scanf("%d", P+i);
	bool turn = false;
	for(int i = 0; i < N-1; ++i){
		for (int j = i+1; j > 1; --j)
			dp[!turn][j] = min(dp[turn][j-1], dp[turn][i+2-j] + P[i]);
		dp[!turn][1] = P[i];
		turn = !turn;
	}
	printf("%d\n", dp[turn][N/2]);
}