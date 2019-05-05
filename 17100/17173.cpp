#include <cstdio>
using namespace std;
const int MAX = 1001;

int main(){
	bool flag[MAX] = {false,};
	int N, M, result = 0;
	scanf("%d %d", &N, &M);
	for(int i = 0; i < M; ++i){
		int K;
		scanf("%d", &K);
		for(int j = K; j <= N; j += K)
			flag[j] = true;
	}
	for(int i = 0; i < MAX; ++i)
		if(flag[i]) result += i;
	printf("%d\n", result);
}