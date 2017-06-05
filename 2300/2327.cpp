#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

int main(){
	int H, N;
	P p[350];
	scanf("%d %d", &H, &N);
	for(int i=0; i<N; i++)
		scanf("%d %d", &p[i].second, &p[i].first);
	sort(p, p+N);

	bool dp[2][100001] = {false};
	dp[N%2][H] = true;
	for(int i=N-1; i>=0; i--){
		int a = i%2, b = !a;
		for(int j=H; j>=0; j--){
			if(!dp[b][j]) continue;
			dp[a][j] = true;
			if(j-p[i].second >= 0) dp[a][j-p[i].second] = true;
		}
		if(dp[a][0]){
			printf("%d\n", p[i].first);
			return 0;
		}
	}
}