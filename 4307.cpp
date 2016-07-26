#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int L, N, x;
		scanf("%d %d", &L, &N);
		int fastest = 0, slowest = 0;
		for(int i=0; i<N; i++){
			scanf("%d", &x);
			fastest = max(fastest, min(x, L-x));
			slowest = max(slowest, max(x, L-x));
		}
		printf("%d %d\n", fastest, slowest);
	}
}