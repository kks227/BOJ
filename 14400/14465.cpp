#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, K, B;
	scanf("%d %d %d", &N, &K, &B);
	bool broken[100000] = {0};
	for(int i=0; i<B; i++){
		int b;
		scanf("%d", &b);
		broken[b-1] = true;
	}

	int cnt = 0;
	for(int i=0; i<K; i++)
		cnt += broken[i];
	int result = cnt;
	for(int i=K; i<N; i++){
		if(broken[i]) cnt++;
		if(broken[i-K]) cnt--;
		result = min(result, cnt);
	}
	printf("%d\n", result);
}