#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N, K, result = 0;
		scanf("%d %d", &N, &K);
		for(int i=0; i<N; i++){
			int candy;
			scanf("%d", &candy);
			result += candy/K;
		}
		printf("%d\n", result);
	}
}