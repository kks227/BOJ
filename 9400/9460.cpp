#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 10000;
const int INF = 1e9;
typedef pair<int, int> P;

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		int N, K;
		P p[MAX];
		scanf("%d %d", &N, &K);
		for(int i = 0; i < N; ++i){
			int x, y;
			scanf("%d %d", &x, &y);
			p[i] = P(x, y*2);
		}
		sort(p, p+N);

		int lo = -1, hi = INF;
		while(lo+1 < hi){
			int mid = (lo+hi)/2;

			int k = 1, s = p[0].second - mid, e = p[0].second + mid;
			for(int i = 1; i < N; ++i){
				int s1 = p[i].second - mid, e1 = p[i].second + mid;
				if(e1 < s || e < s1){
					if(++k > K) break;
					s = s1;
					e = e1;
				}
				else{
					e = min(e, e1);
					s = max(s, s1);
				}
			}
			(k <= K ? hi : lo) = mid;
		}
		printf("%.1lf\n", hi/2.0);
	}
}