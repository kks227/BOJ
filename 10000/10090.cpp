#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1000000;
const int INF = 1e9;

long long cntInv(int N, vector<int> &A){
	if(N <= 1) return 0;
	int M = N/2;
	vector<int> L(M), R(N-M);
	copy(A.begin(), A.begin()+M, L.begin());
	copy(A.begin()+M, A.end(), R.begin());
	long long result = cntInv(M, L) + cntInv(N-M, R);
	for(int i = 0, j = 0, k = 0; k < N; ++k){
		int p = (i < M ? L[i] : INF), q = (j < N-M ? R[j] : INF);
		if(p < q) A[k] = L[i++];
		else{
			result += M-i;
			A[k] = R[j++];
		}
	}
	return result;
}

int main(){
	int N;
	scanf("%d", &N);
	vector<int> A(N);
	for(int i = 0; i < N; ++i)
		scanf("%d", &A[i]);
	printf("%lld\n", cntInv(N, A));
}