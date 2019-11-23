#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
const int N = 11;
typedef pair<int, int> P;

int main(){
	P p[N];
	for(int i = 0; i < N; ++i)
		scanf("%d %d", &p[i].first, &p[i].second);
	sort(p, p+N);
	int result = 0, sum = 0;
	for(int i = 0; i < N; ++i){
		sum += p[i].first;
		result += sum + p[i].second * 20;
	}
	printf("%d\n", result);
}