#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, A[100000], B[100000], dp[100001][6];

int graphix(int pos, int g){
	int &ret = dp[pos][g];
	if(ret != -1) return ret;
	if(pos == N) return ret = 0;
	if(g != A[pos] && g != B[pos]) return ret = 0;
	return ret = graphix(pos+1, g) + 1;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d %d", A+i, B+i);
	memset(dp, -1, sizeof(dp));
	int result = 0, val = -1;
	for(int i=0; i<N; i++){
		if(result < graphix(i, A[i])){
			result = graphix(i, A[i]);
			val = A[i];
		}
		if(result < graphix(i, B[i])){
			result = graphix(i, B[i]);
			val = B[i];
		}
	}
	printf("%d %d\n", result, val);
}