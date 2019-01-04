#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;
typedef pair<long long, int> P;

int main(){
	int N, T, D[100000];
	scanf("%d %d", &N, &T);
	for(int i = 0; i < N; ++i)
		scanf("%d", D+i);
	int lo = 0, hi = N;
	while(lo+1 < hi){
		int mid = (lo+hi)/2;
		long long temp = 0;
		priority_queue<P, vector<P>, greater<P>> PQ;
		for(int i = 0; i < min(mid, N); ++i){
			PQ.push(P(D[i], i));
			temp = max(1LL*D[i], temp);
		}
		for(int i = mid; i < N; ++i){
			P p(PQ.top().first + D[i], PQ.top().second);
			PQ.pop();
			temp = max(p.first, temp);
			PQ.push(p);
		}
		(temp <= T ? hi : lo) = mid;
	}
	printf("%d\n", hi);
}