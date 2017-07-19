#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
	char S[200001] = {0};
	scanf("%s", S);
	int N = strlen(S);
	for(int i=N-1; i>=0; i--){
		S[i*2+1] = S[i];
		S[i*2] = '.';
	}
	N *= 2;
	S[N++] = '.';
	int R = -1, p = -1, A[200001] = {0};
	for(int i=0; i<N; i++){
		A[i] = (i <= R ? min(A[2*p-i], R-i) : 0);
		while(i-A[i]-1 >= 0 && i+A[i]+1 < N && S[i-A[i]-1] == S[i+A[i]+1]) A[i]++;
		if(i+A[i] > R){
			R = i+A[i];
			p = i;
		}
	}
	int result = 0;
	for(int i=0; i<N; i++)
		result = max(result, A[i]);
	printf("%d\n", result);
}