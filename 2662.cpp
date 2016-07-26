#include <cstdio>
#include <cstring>
using namespace std;

int M, N, benefit[301][20], dp[301][20], result[301][20];

int maxBenefit(int spare, int pos){
	if(spare==0 || pos==N) return 0;
	int &ret = dp[spare][pos];
	if(ret != -1) return ret;

	ret = maxBenefit(spare, pos+1);
	result[spare][pos] = 0;
	for(int i=1; i<=spare; i++){
		int temp = maxBenefit(spare-i, pos+1) + benefit[i][pos];
		if(temp > ret){
			ret = temp;
			result[spare][pos] = i;
		}
	}
	return ret;
}

void trace(int spare, int pos){
	if(pos == N) return;
	printf("%d ", result[spare][pos]);
	trace(spare-result[spare][pos], pos+1);
}

int main(){
	scanf("%d %d", &M, &N);
	for(int i=0; i<M; i++){
		int cost;
		scanf("%d", &cost);
		for(int j=0; j<N; j++)
			scanf("%d", &benefit[cost][j]);
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", maxBenefit(M, 0));
	trace(M, 0);
}