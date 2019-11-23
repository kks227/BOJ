#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, result = 0, m;
	scanf("%d %d", &N, &m);
	for(int i = 1; i < N; ++i){
		int A;
		scanf("%d", &A);
		result = max(A-m, result);
		m = min(m, A);
	}
	printf("%d\n", result);
}