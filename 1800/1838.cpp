#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 500000;
typedef pair<int, int> P;

int main(){
	int N;
	P p[MAX];
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		int a;
		scanf("%d", &a);
		p[i] = P(a, i);
	}
	stable_sort(p, p+N);
	int result = 0;
	for(int i = 0; i < N; ++i)
		result = max(p[i].second - i, result);
	printf("%d\n", result);
}