#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, M, A[30][30], result = 0, chosen[3];
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < M; ++j)
			scanf("%d", &A[i][j]);
	for(chosen[0] = 0; chosen[0] < M; ++chosen[0]){
		for(chosen[1] = 0; chosen[1] < M; ++chosen[1]){
			for(chosen[2] = 0; chosen[2] < M; ++chosen[2]){
				int sum = 0;
				for(int i = 0; i < N; ++i){
					int temp = 0;
					for(int j = 0; j < 3; ++j)
						temp = max(A[i][chosen[j]], temp);
					sum += temp;
				}
				result = max(sum, result);
			}
		}
	}
	printf("%d\n", result);
}