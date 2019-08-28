#include <cstdio>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 200000;
typedef pair<int, int> P;

int main(){
	int N;
	P p[MAX];
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%d %d", &p[i].first, &p[i].second);
		--p[i].first;
	}
	sort(p, p+N);
	priority_queue<int> PQ;
	int result = 0, k = N-1;
	for(int i = N-1; i >= 0; --i){
		for(; k >= 0 && p[k].first == i; --k)
			PQ.push(p[k].second);
		if(!PQ.empty()){
			result += PQ.top();
			PQ.pop();
		}
	}
	printf("%d\n", result);
}