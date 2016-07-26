#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int T, W, dp[1000][31];
bool left[1000];

int maxCherry(int t, int w, bool side){
	if(t == T) return 0;
	int &ret = dp[t][w];
	if(ret != -1) return ret;

	ret = maxCherry(t+1, w, side) + (left[t] == side);
	if(w) ret = max(ret, maxCherry(t+1, w-1, !side) + (left[t] == !side));
	return ret;
}

int main(){
	scanf("%d %d", &T, &W);
	for(int i=0; i<T; i++){
		int n;
		scanf("%d", &n);
		left[i] = (n == 1);
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", maxCherry(0, W, true));
}