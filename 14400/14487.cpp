#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, S = 0, M = 0;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int val;
		scanf("%d", &val);
		S += val;
		M = max(M, val);
	}
	printf("%d\n", S-M);
}