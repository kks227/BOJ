#include <cstdio>
using namespace std;
const int MAX = 100000;

int main(){
	int N, B, pos, A[MAX], cnt[2][MAX*2+1] = {0,};
	scanf("%d %d", &N, &B);
	for(int i = 0; i < N; ++i){
		scanf("%d", A+i);
		if(A[i] == B) pos = i;
	}
	cnt[0][MAX] = cnt[1][MAX] = 1;
	int temp = 0;
	for(int i = pos-1; i >= 0; --i){
		temp += (A[i] > B ? 1 : -1);
		++cnt[0][temp+MAX];
	}
	temp = 0;
	for(int i = pos+1; i < N; ++i){
		temp += (A[i] > B ? 1 : -1);
		++cnt[1][temp+MAX];
	}
	long long result = 0;
	for(int i = 0; i <= MAX*2; ++i)
		result += 1LL * cnt[0][i] * cnt[1][MAX*2-i];
	printf("%lld\n", result);
}