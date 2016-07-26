#include <cstdio>
#include <algorithm>
using namespace std;
const int UNDEFINED = -1000000000;
const int IMPOSSIBLE = 1000000000;

int N, M, val[100], dp[100][50];

int maxSubsetSum(int pos, int used){
	if(used == M) return 0;
	if(pos >= N) return IMPOSSIBLE;
	int &ret = dp[pos][used];
	if(ret != UNDEFINED) return ret;

	int temp = maxSubsetSum(pos+1, used);
	if(temp != IMPOSSIBLE) ret = temp;
	int sum = 0;
	for(int i=pos; i<N; i++){
		sum += val[i];
		temp = maxSubsetSum(i+2, used+1);
		if(temp != IMPOSSIBLE) ret = max(ret, temp+sum);
	}
	if(ret == UNDEFINED) ret = IMPOSSIBLE;
	return ret;
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++)
		scanf("%d", val+i);
	for(int i=0; i<100; i++)
		for(int j=0; j<50; j++)
			dp[i][j] = UNDEFINED;
	printf("%d\n", maxSubsetSum(0, 0));
}