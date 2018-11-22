#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int main(){
	int N[3], A[3][1000], result = INF;
	scanf("%d %d %d", N, N+1, N+2);
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < N[i]; ++j)
			scanf("%d", &A[i][j]);
		sort(A[i], A[i]+N[i]);
	}
	for(int k = 0; k < 3; ++k){
		int T[2], O, P[2];
		for(int i = 0, j = 0; i < 3 && j < 2; ++i)
			if(i != k) T[j++] = i;
		for(int i = 0; i < N[T[0]]; ++i){
			int a = A[T[0]][i];
			for(int j = 0; j < N[T[1]]; ++j){
				int b = A[T[1]][j];
				int s = min(a, b), e = max(a, b);
				int temp = lower_bound(A[k], A[k]+N[k], s) - A[k];
				if(temp < N[k] && A[k][temp] <= e) result = min(e-s, result);
			}
		}
	}
	printf("%d\n", result);
}