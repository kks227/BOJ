#include <cstdio>
using namespace std;

inline int sum(int k){ return k*(k+1)/2; }

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		int N;
		scanf("%d", &N);
		printf("%d %d %d\n", sum(N), 2*sum(N)-N, 2*sum(N));
	}
}