#include <cstdio>
using namespace std;

int main(){
	int N, result = 0;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int C, K;
		scanf("%d %d", &C, &K);
		result += C*K;
	}
	printf("%d\n", result);
}