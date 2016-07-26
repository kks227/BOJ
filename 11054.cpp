#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, A[1000], dp1[1000], dp2[1000];

int longestISS(int pos){
	if(pos == N) return 0;
	int &ret = dp1[pos];
	if(ret != -1) return ret;

	ret = 0;
	for(int i=pos-1; i>=0; i--)
		if(A[i] < A[pos]) ret = max(ret, longestISS(i));
	return ++ret;
}

int longestDSS(int pos){
	if(pos == N) return 0;
	int &ret = dp2[pos];
	if(ret != -1) return ret;

	ret = 0;
	for(int i=pos+1; i<N; i++)
		if(A[i] < A[pos]) ret = max(ret, longestDSS(i));
	return ++ret;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", A+i);
	memset(dp1, -1, sizeof(dp1));
	memset(dp2, -1, sizeof(dp2));
	int result = 0;
	for(int i=0; i<N; i++)
		result = max(result, longestISS(i) + longestDSS(i) - 1);
	printf("%d\n", result);
}