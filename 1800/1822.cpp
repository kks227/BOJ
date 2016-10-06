#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int M, N, A[500000], B[500000];
	scanf("%d %d", &M, &N);
	for(int i=0; i<M; i++)
		scanf("%d", A+i);
	for(int i=0; i<N; i++)
		scanf("%d", B+i);
	sort(A, A+M);
	sort(B, B+N);

	vector<int> result(M+N);
	auto iter = set_difference(A, A+M, B, B+N, result.begin());
	result.resize(iter-result.begin());
	printf("%d\n", result.size());
	if(!result.empty()){
		for(int i=0; i<result.size(); i++)
			printf("%d ", result[i]);
	}
}