#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, A[100000];
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", A+i);

	int result = 1, s = 0, e = 0;
	for(int i=1; i<N; i++){
		if(A[i] > A[i-1]) e++;
		else{
			int temp = 1;
			int j = i, k = i-2;
			bool odd = true;
			if(A[i] == A[i-1]){
				j++;
				odd = false;
			}
			for(; j<N && k>=s; j++, k--){
				if(A[j] != A[k]) break;
				temp++;
			}
			result = max(temp*2 - odd, result);

			s = e = i = j;
			if(i > 0 && A[i-1] < A[i]) s = i-1;
		}
	}
	printf("%d\n", result);
}