#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 100000;
const int INF = 1e9;
typedef pair<int, int> P;

int main(){
	int N, K;
	P p[MAX];
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N; ++i)
		scanf("%d %d", &p[i].second, &p[i].first);
	sort(p, p+N);

	long long result = 0, pSum[MAX+1] = {0,};
	for(int i = 0; i < N; ++i)
		pSum[i+1] = pSum[i] + p[i].second;
	for(int i = 0; i < N; ++i){
		int j = upper_bound(p, p+N, P(p[i].first + 2*K, INF)) - p;
		result = max(pSum[j]-pSum[i], result);
	}
	printf("%lld\n", result);
}