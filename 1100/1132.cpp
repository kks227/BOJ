#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
	int N, L[50];
	long long sum[10] = {0}, result = 0;
	char S[50][13];
	bool impossible[10] = {0};
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%s", S[i]);
		L[i] = strlen(S[i]);
		impossible[S[i][0]-'A'] = true;
		for(long long j=L[i]-1, k=1; j>=0; j--, k*=10) sum[S[i][j]-'A'] += k;
	}

	int p[10];
	for(int i=0; i<10; i++) p[i] = i;
	do{
		if(impossible[p[0]]) continue;
		long long temp = 0;
		for(int i=1; i<10; i++) temp += sum[p[i]]*i;
		result = max(result, temp);
	}while(next_permutation(p, p+10));
	printf("%lld\n", result);
}