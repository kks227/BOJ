#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

int main(){
	int N, M, D = 0, K = 0;
	P p[300000];
	scanf("%d %d", &N, &M);
	D = M;
	for(int i=0; i<N; i++){
		int S, E;
		scanf("%d %d", &S, &E);
		D = max(max(S, E), D);
		if(S > E && E < M) p[K++] = P(E, min(S, M));
	}
	sort(p, p+K);

	long long result = D + (D-M);
	int l = -1, r = -1;
	for(int i=0; i<K; i++){
		if(r < p[i].first){
			result += 2*(r-l);
			l = p[i].first;
			r = p[i].second;
		}
		else r = max(r, p[i].second);
	}
	result += 2*(r-l);
	printf("%lld\n", result);
}