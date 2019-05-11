#include <cstdio>
using namespace std;
const int MAX = 100000;
const int INF = 1e9 + 1;

int main(){
	int N, A[MAX];
	bool sorted[2][MAX] = {false,};
	scanf("%d", &N);
	sorted[0][0] = sorted[1][N-1] = true;
	for(int i = 0; i < N; ++i){
		scanf("%d", A+i);
		if(i > 0 && sorted[0][i-1] && A[i-1] <= A[i]) sorted[0][i] = true;
	}
	for(int i = N-2; i >= 0; --i){
		if(sorted[1][i+1] && A[i+1] >= A[i]) sorted[1][i] = true;
		else break;
	}
	int result = 0;
	for(int i = 0; i < N; ++i){
		int a = (i == 0 ? -INF : A[i-1]), b = (i == N-1 ? INF : A[i+1]);
		bool flag = (a <= b);
		if(i > 0 && !sorted[0][i-1]) flag = false;
		if(i < N-1 && !sorted[1][i+1]) flag = false;
		if(flag) ++result;
	}
	printf("%d\n", result);
}