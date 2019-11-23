#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 100000;
typedef pair<int, int> P;

int main(){
	int N;
	long long M;
	P p[MAX];
	scanf("%d %lld", &N, &M);
	for(int i = 0; i < N; ++i)
		scanf("%d", &p[i].first);
	for(int i = 0; i < N; ++i)
		scanf("%d", &p[i].second);
	sort(p, p+N);
	for(int i = 0; i < N && M >= p[i].first; ++i)
		if(p[i].first < p[i].second) M += p[i].second - p[i].first;
	printf("%lld\n", M);
}