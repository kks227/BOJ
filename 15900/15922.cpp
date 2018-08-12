#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

int main(){
	int N;
	P p[100000];
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d %d", &p[i].first, &p[i].second);
	sort(p, p+N, [](auto &a, auto &b){
		return P(a.first, -a.second) < P(b.first, -b.second);
	});

	int s = p[0].first, e = p[0].second, result = 0;
	for(int i=1; i<N; i++){
		if(p[i].first > e){
			result += e-s;
			s = p[i].first;
			e = p[i].second;
		}
		else e = max(p[i].second, e);
	}
	result += e-s;
	printf("%d\n", result);
}