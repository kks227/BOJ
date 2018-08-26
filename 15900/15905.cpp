#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

int main(){
	int N;
	P p[66];
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d %d", &p[i].first, &p[i].second);
	sort(p, p+N, [](auto &a, auto &b){
		if(a.first != b.first) return a.first > b.first;
		return a.second < b.second;
	});
	int result = 0;
	for(int i=5; i<N && p[i].first == p[4].first; i++) result++;
	printf("%d\n", result);
}