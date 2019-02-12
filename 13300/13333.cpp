#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, Q[1001] = {0};
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		scanf("%d", Q+i);
	sort(Q, Q+N);
	for(int i = N; ; --i){
		if(Q[N-i] >= i){
			printf("%d\n", i);
			return 0;
		}
	}
}