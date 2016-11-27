#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

int main(){
	int N, L;
	scanf("%d %d", &N, &L);
	P p[10000];
	for(int i=0; i<N; i++)
		scanf("%d %d", &p[i].first, &p[i].second);
	sort(p, p+N);

	int pos = 0, result = 0;
	for(int i=0; i<N; i++){
		if(pos >= p[i].second) continue;
		pos = max(pos, p[i].first);
		int temp = (p[i].second-pos-1) / L + 1;
		result += temp;
		pos += temp * L;
	}
	printf("%d\n", result);
}