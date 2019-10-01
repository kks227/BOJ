#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 200000;
const long long INF = 1e10;
typedef pair<int, int> P;

int main(){
	int N, M, K;
	P p[MAX];
	scanf("%d %d %d", &N, &M, &K);
	for(int i = 0; i < K; ++i)
		scanf("%d %d", &p[i].first, &p[i].second);
	sort(p, p+K);

	long long lo = 0, hi = INF;
	while(lo+1 < hi){
		long long mid = (lo+hi)/2;
		int cnt = 0, sum = 0;
		for(int i = K-1; i >= 0; --i){
			if(p[i].second > mid) continue;
			sum += p[i].first;
			if(++cnt == N) break;
		}
		(sum >= M && cnt == N ? hi : lo) = mid;
	}
	printf("%lld\n", hi == INF ? -1 : hi);
}