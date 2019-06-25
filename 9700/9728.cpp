#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 20000;

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t){
		int N, M, A[MAX];
		scanf("%d %d", &N, &M);
		for(int i = 0; i < N; ++i)
			scanf("%d", A+i);
		sort(A, A+N);
		int result = 0;
		for(int i = 0; i < N && A[i]*2 < M; ++i)
			if(binary_search(A+i+1, A+N, M-A[i])) ++result;
		printf("Case #%d: %d\n", t, result);
	}
}