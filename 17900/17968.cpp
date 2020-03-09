#include <cstdio>
using namespace std;
const int MAX = 1001;

int main(){
	int A[MAX] = {1, 1,}, N;
	scanf("%d", &N);
	for(int i = 2; i <= N; ++i){
		bool flag[MAX*2] = {false,};
		for(int k = 1; k*2 <= i; ++k){
			int u = i - k, v = i - 2*k, x = A[u] - A[v], y = A[u] + x;
			if(y > 0) flag[y] = true;
		}
		for(int k = 1; ; ++k){
			if(!flag[k]){
				A[i] = k;
				break;
			}
		}
	}
	printf("%d\n", A[N]);
}