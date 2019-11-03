#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N = 1000000;
const int MAX = MAX_N*2 + 2;

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		int N, C[MAX+1];
		scanf("%d", &N);
		getchar();
		for(int i = 0; i < N; ++i){
			char c = getchar();
			C[N-i-1] = (c == '?' ? -1 : c - '0');
		}
		for(int k = 1; k >= 0; --k){
			int A[MAX+1] = {0,}, B[MAX+1] = {0,};
			for(int i = 0; i < N; ++i){
				A[i] = 0;
				B[i] = C[i];
				if(B[i] == -1) B[i] = k;
				A[N+i] = B[i];
			}
			bool carry = false;
			for(int i = 0; i < MAX; ++i){
				int d = A[i] - carry - B[i];
				if(d < 0){
					carry = true;
					d += 2;
				}
				else carry = false;
				A[i] = d;
			}
			int result = MAX;
			for(; result > 0 && A[result] == 0; --result);
			printf("%d ", result+1);
		}
		puts("");
	}
}