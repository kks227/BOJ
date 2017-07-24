#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 4000;

int main(){
	int N, K = 0, arr[MAX][4], sum[MAX*MAX];
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		for(int j=0; j<4; j++)
			scanf("%d", &arr[i][j]);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			sum[K++] = arr[i][0] + arr[j][1];
	sort(sum, sum+K);
	long long result = 0;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			int k = -arr[i][2]-arr[j][3];
			result += upper_bound(sum, sum+K, k) - lower_bound(sum, sum+K, k);
		}
	}
	printf("%lld\n", result);
}