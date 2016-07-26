#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> intPair;

int main(){
	int N;
	intPair times[100000];
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int start, end;
		scanf("%d %d", &start, &end);
		times[i] = intPair(end, start);
	}
	sort(times, times+N);
	int result = 0, limit = 0;
	for(int i=0; i<N; i++){
		if(times[i].second >= limit){
			limit = times[i].first;
			result++;
		}
	}
	printf("%d\n", result);
}