#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int main(){
	int N, M, pSum[100000] = {0};
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; ++i){
		int val;
		scanf("%d", &val);
		pSum[i+1] = pSum[i] + val;
	}
	int result = 0, temp = 0;
	for(int i = M-1; i < N; ++i){
		temp = min(pSum[i-M+1], temp);
		result = max(pSum[i+1] - temp, result);
	}
	printf("%d\n", result);
}