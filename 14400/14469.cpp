#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 100;
typedef pair<int, int> P;

int main(){
	int N, result = 0;
	P p[MAX];
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		scanf("%d %d", &p[i].first, &p[i].second);
	sort(p, p+N);
	for(int i = 0; i < N; ++i){
		if(result >= p[i].first) result += p[i].second;
		else result = p[i].first + p[i].second;
	}
	printf("%d\n", result);
}