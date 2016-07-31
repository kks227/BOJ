#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, w[100000];
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", w+i);

	// 잘 버티는 로프 순으로 오름차순 정렬
	sort(w, w+N);
	
	int result = 0;
	for(int i=1; i<=N; i++)
		result = max(result, w[N-i]*i);
	printf("%d\n", result);
}