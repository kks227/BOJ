#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int, int> P;

int main(){
	int N;
	P p[1000];
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d %d", &p[i].first, &p[i].second);
	sort(p, p+N, [](P &a, P &b){
		if(a.second != b.second) return a.second > b.second;
		return a.first < b.first;
	});

	int result[1000] = {0}, pos = 0;
	for(int i=0; i<N; i++){
		int j = p[i].first-1;
		for(; result[j] && j>=0; j--);
		if(j >= 0) result[j] = p[i].second;
	}
	int sum = 0;
	for(int i=0; i<1000; i++)
		sum += result[i];
	printf("%d\n", sum);
}