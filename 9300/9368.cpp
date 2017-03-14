#include <cstdio>
#include <algorithm>
using namespace std;

int N, C, M, B[16], P[16];
double dp[17][1<<16];

double bribe(int remain, int visited){
	double &ret = dp[remain][visited];
	if(ret >= 0) return ret;
	if(remain == 0) return ret = 1;

	int spare = M, cnt = N;
	for(int i=0; i<N; i++){
		if(visited & 1<<i){
			spare -= B[i];
			cnt--;
		}
	}
	if(cnt < remain) return ret = 0;

	ret = 0;
	for(int i=0; i<N; i++){
		if(visited & 1<<i || spare < B[i]) continue;
		ret = max(ret, (bribe(remain-1, visited | 1<<i)*P[i] + bribe(remain, visited | 1<<i)*(100-P[i]))/100);
	}
	return ret;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		scanf("%d %d %d", &N, &C, &M);
		for(int i=0; i<N; i++)
			scanf("%d %d", B+i, P+i);
		for(int i=0; i<=C; i++)
			fill(dp[i], dp[i]+(1<<N), -1);
		printf("%.7lf\n", bribe(C, 0));
	}
}