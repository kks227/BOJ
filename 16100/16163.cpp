#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 2000000;

int main(){
	char S[2*MAX+1] = {0};
	scanf("%s", S);
	int N = strlen(S);
	for(int i=N-1; i>=0; i--){
		S[i*2+1] = S[i];
		S[i*2] = '.';
	}
	N *= 2;
	S[N++] = '.';
	int R = -1, p = -1, A[2*MAX+1] = {0};
	for(int i=0; i<N; i++){
		A[i] = (i <= R ? min(A[2*p-i], R-i) : 0);
		while(i-A[i]-1 >= 0 && i+A[i]+1 < N && S[i-A[i]-1] == S[i+A[i]+1]) A[i]++;
		if(i+A[i] > R){
			R = i+A[i];
			p = i;
		}
	}
	long long result = 0;
	for(int i=0; i<N; i++)
		result += (A[i]+1)/2;
	printf("%lld\n", result);
}