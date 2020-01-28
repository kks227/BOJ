#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAX = 5000;
const long long INF = 1e18;

int main(){
	int N, A[MAX];
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		scanf("%d", A+i);
	sort(A, A+N);

	long long result = INF;
	int rpos[3];
	for(int i = 1; i < N-1; ++i){
		long long sum = A[i];
		int j = i-1, k = i+1;
		sum += A[j] + A[k];
		if(abs(sum) < result){
			result = abs(sum);
			rpos[0] = j; rpos[1] = i; rpos[2] = k;
		}
		while(j > 0 || k < N-1){
			if(j > 0 && sum > 0 || k == N-1){
				sum += A[j-1] - A[j];
				--j;
			}
			else{
				sum += A[k+1] - A[k];
				++k;
			}
			if(abs(sum) < result){
				result = abs(sum);
				rpos[0] = j; rpos[1] = i; rpos[2] = k;
			}
		}
	}
	for(int i = 0; i < 3; ++i)
		printf("%d ", A[rpos[i]]);
}