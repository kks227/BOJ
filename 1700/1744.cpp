#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;
const int UNDEF = INT_MIN;

int N, arr[10000], dp[10001];

int bind(int pos){
	int &ret = dp[pos];
	if(ret > UNDEF) return ret;
	if(pos == N) return ret = 0;
	if(pos == N-1) return ret = arr[pos];
	return ret = max(bind(pos+1) + arr[pos], bind(pos+2) + arr[pos]*arr[pos+1]);
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", arr+i);
	fill(dp, dp+10001, UNDEF);
	sort(arr, arr+N);
	printf("%d\n", bind(0));
}