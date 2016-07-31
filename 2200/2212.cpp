#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, K, pos[10000], dif[9999];
	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++)
		scanf("%d", pos+i);

	// 집중국이 마을 개수 이상이면 모든 집중국이 점이어도 됨
	if(K >= N) puts("0");
	// 아닐 경우
	else{
		// 먼저 마을 좌표를 정렬
		sort(pos, pos+N);
		// 인접한 마을끼리 거리 값들을 구해 정렬
		for(int i=0; i<N-1; i++)
			dif[i] = pos[i+1] - pos[i];
		sort(dif, dif+N-1);

		// 가장 멀리 떨어진 두 도시부터 서로 다른 집중국에 속하도록 결정
		// 즉, 가장 먼 거리값부터 빼나감
		int result = 0;
		for(int i=0; i<K-1; i++)
			result += dif[N-2-i];
		printf("%d\n", pos[N-1]-pos[0]-result);
	}
}