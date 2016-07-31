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

	// 끝나는 시간이 빠른 순으로 정렬
	sort(times, times+N);
	
	// limit: 바로 전 회의가 끝난 시간
	int result = 0, limit = 0;
	for(int i=0; i<N; i++){
		if(times[i].second >= limit){
			limit = times[i].first;
			result++;
		}
	}
	printf("%d\n", result);
}