#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int INF = 1e9+1;

int main(){
	int N;
	scanf("%d", &N);
	P L[1000000];
	for(int i=0; i<N; i++){
		int s, e;
		scanf("%d %d", &s, &e);
		L[i] = P(s, e);
	}
	sort(L, L+N);

	int result = 0, l = -INF, r = -INF;
	for(int i=0; i<N; i++){
		if(r < L[i].first){
			result += r-l;
			l = L[i].first;
			r = L[i].second;
		}
		else r = max(r, L[i].second);
	}
	result += r-l;
	printf("%d\n", result);
}