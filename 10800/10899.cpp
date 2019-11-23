#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 100000;

int main(){
	int P, N, A[MAX];
	scanf("%d %d", &P, &N);
	for(int i = 0; i < N; ++i)
		scanf("%d", A+i);
	sort(A, A+N);
	int cnt = 0, remain = P-1, t[MAX];
	long long result = 0;
	for(int i = 0; i < N && remain >= A[i]; ++i){
		result += remain;
		remain -= A[i];
		++cnt;
	}
	printf("%d %lld\n", cnt, result);
}