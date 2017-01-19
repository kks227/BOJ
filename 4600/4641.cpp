#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	while(1){
		int A[16], N;
		for(N=0; ; N++){
			scanf("%d", A+N);
			if(A[N] <= 0) break;
		}
		if(A[0] == -1) break;

		sort(A, A+N);
		int result = 0;
		for(int i=0; i<N; i++)
			if(binary_search(A, A+N, A[i]*2)) result++;
		printf("%d\n", result);
	}
}