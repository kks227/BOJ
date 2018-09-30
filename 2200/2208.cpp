#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;
const int INF = 1e9;

int main(){
	int N, M, pSum[100000] = {0};
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		int val;
		scanf("%d", &val);
		pSum[i+1] = pSum[i] + val;
	}
	int result = 0;
	priority_queue<int, vector<int>, greater<int>> PQ;
	for(int i=M-1; i<N; i++){
		PQ.push(pSum[i-M+1]);
		result = max(pSum[i+1]-PQ.top(), result);
	}
	printf("%d\n", result);
}