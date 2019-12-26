#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 100000;
const int MAX_VAL = 1000002;

int N, A[MAX], dp[MAX+1];
vector<int> pos[MAX_VAL];

int seq(int curr){
	int &ret = dp[curr];
	if(ret != -1) return ret;
	if(curr == N) return ret = 0;
	int k = A[curr] + 1;
	int next = upper_bound(pos[k].begin(), pos[k].end(), curr) - pos[k].begin();
	return ret = (next == pos[k].size() ? 0 : seq(pos[k][next])) + 1;
}

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%d", A+i);
		pos[A[i]].push_back(i);
	}
	fill(dp, dp+MAX, -1);
	int result = 1;
	for(int i = 0; i < N; ++i)
		result = max(seq(i), result);
	printf("%d\n", result);
}