#include <cstdio>
#include <utility>
#include <set>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

int main(){
	int N;
	P p[200000];
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int S, T;
		scanf("%d %d", &S, &T);
		p[i] = P(S, T);
	}
	sort(p, p+N);

	multiset<int> S;
	for(int i=0; i<N; i++){
		auto finder = S.lower_bound(-p[i].first);
		if(finder != S.end()) S.erase(finder);
		S.insert(-p[i].second);
	}
	printf("%d\n", S.size());
}