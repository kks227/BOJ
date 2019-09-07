#include <cstdio>
using namespace std;
const int MAX = 10;

int N, A[MAX];
long long M, P = 1, result;

void backtrack(int pos, int cnt){
	if(pos == N){
		if(cnt > 0) result += (M / P) * (cnt%2 ? 1 : -1);
		return;
	}
	backtrack(pos+1, cnt);
	P *= A[pos];
	backtrack(pos+1, cnt+1);
	P /= A[pos];
}

int main(){
	scanf("%d %lld", &N, &M);
	for(int i = 0; i < N; ++i)
		scanf("%d", A+i);
	backtrack(0, 0);
	printf("%lld\n", result);
}