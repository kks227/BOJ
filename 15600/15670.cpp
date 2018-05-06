#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

int main(){

	int N, M, j, A[100000], PN[2] = {0}, pn[2][100000] = {0};
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++)
		scanf("%d", A+i);
	vector<P> S[2];

	j = 0;
	for(int i=1; i<N; i++){
		if(A[i] < A[i-1]){
			S[0].push_back(P(j, i-1));
			j = i;
			PN[0]++;
		}
		pn[0][i] = PN[0];
	}
	S[0].push_back(P(j, N-1));
	PN[0]++;

	j = N-1;
	for(int i=N-2; i>=0; i--){
		if(A[i] < A[i+1]){
			S[1].push_back(P(i+1, j));
			j = i;
			PN[1]++;
		}
		pn[1][i] = PN[1];
	}
	S[1].push_back(P(0, j));
	PN[1]++;
	reverse(S[1].begin(), S[1].end());

	for(int i=0; i<M; i++){
		int L, R, result = 0;
		scanf("%d %d", &L, &R);
		L--; R--;

		if(L > 0) result += pn[0][L-1] + 1;
		if(R < N-1) result += PN[0] - pn[0][R+1];

		result += pn[1][L] - pn[1][R] + 1;

		if(L > 0 && A[L-1] < A[R]) result--;
		if(R < N-1 && A[L] < A[R+1]) result--;

		printf("%d\n", result);
	}
}