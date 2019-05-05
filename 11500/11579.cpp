#include <cstdio>
using namespace std;
const int MAX = 500;
const int LIMIT = 1e9 * 2;

int solve(){
	int N, y[MAX], move[MAX][MAX];
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			scanf("%d", &move[i][j]);
	for(int i = 0; i < N; ++i)
		scanf("%d", y+i);

	long long x[MAX] = {0,}, result = 0;
	for(int i = 0; i < N; ++i){
		if(x[i] > y[i]) return -1;
		else if(x[i] == y[i]) continue;
		int temp = y[i] - x[i];
		if(temp % move[i][i] != 0) return -1;
		temp /= move[i][i];
		result += temp;
		if(result > LIMIT) return -1;
		for(int j = i; j < N; ++j)
			x[j] += move[i][j] * temp;
	}
	return result;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		int result = solve();
		if(result < 0) puts("0");
		else printf("1 %d\n", result);
	}
}