#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

int main(){
	int N;
	P p[500000];
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		p[i].second = i;
		scanf("%d", &p[i].first);
	}
	stable_sort(p, p+N);
	int result = 0;
	for(int i=0; i<N; i++)
		if(p[i].second > i) result = max(result, p[i].second-i);
	printf("%d\n", result+1);
}