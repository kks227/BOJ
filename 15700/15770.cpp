#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 10000;

int main(){
	int Q, result[MAX] = {0};
	scanf("%d\n", &Q);
	char S[2*MAX+1] = {'.',};
	for(int i=1; i<=MAX; i++) S[i*2] = '.';
	for(int q=0, N=1; q<Q; q++){
		char c = getchar();
		if(c == '-'){
			S[N] = '\0';
			result[N/2] = 0;
			N -= 2;
		}
		else{
			S[N] = c;
			N += 2;
		}

		if(result[N/2] == 0){
			int R = -1, p = -1, A[2*MAX+1] = {0};
			for(int i=0; i<N; i++){
				A[i] = (i <= R ? min(A[2*p-i], R-i) : 0);
				while(i-A[i]-1 >= 0 && i+A[i]+1 < N && S[i-A[i]-1] == S[i+A[i]+1]) A[i]++;
				if(i+A[i] > R){
					R = i+A[i];
					p = i;
				}
			}
			for(int i=0; i<N; i++)
				result[N/2] += (A[i]+1)/2;
		}
		printf("%d ", result[N/2]);
	}
}