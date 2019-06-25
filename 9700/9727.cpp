#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 6;
const int K = N*3+2;

int main(){
	int T, r[K][N], c[K][N];
	scanf("%d", &T);
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			r[i][j] = c[N+i][j] = i;
			c[i][j] = r[N+i][j] = j;
		}
	}
	for(int i = 0; i < N; ++i){
		int r0 = i/2*2, c0 = i%2*(N/2);
		for(int j = 0; j < N; ++j){
			r[N*2+i][j] = r0 + j/(N/2);
			c[N*2+i][j] = c0 + j%(N/2);
		}
	}
	for(int i = 0; i < N; ++i){
		r[N*3][i] = i;
		c[N*3][i] = i;
		r[N*3+1][i] = i;
		c[N*3+1][i] = N-i-1;
	}

	for(int t = 1; t <= T; ++t){
		int A[N][N];
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < N; ++j)
				scanf("%d", &A[i][j]);
		bool result = true;
		for(int i = 0; result && i < K; ++i){
			bool check[N+1] = {false,};
			for(int j = 0; j < N; ++j){
				int d = A[r[i][j]][c[i][j]];
				if(check[d]){
					result = false;
					break;
				}
				check[d] = true;
			}
		}
		printf("Case#%d: %d\n", t, result);
	}
}