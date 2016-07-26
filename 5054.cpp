#include <cstdio>
#include <algorithm>
using namespace std;

int main(){

	int T, N, x, large, small;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		scanf("%d", &N);
		large = 0;
		small = 100;
		for(int i=0; i<N; i++){
			scanf("%d", &x);
			large = max(large, x);
			small = min(small, x);
		}
		printf("%d\n", (large-small)*2);
	}

	return 0;
}