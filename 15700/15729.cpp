#include <cstdio>
using namespace std;

int main(){
	int N, result = 0;
	bool A[1000000] = {0}, B[1000000];
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", B+i);
	for(int i=0; i<N; i++){
		if(A[i] != B[i]){
			result++;
			for(int j=0; j<3 && i+j<N; j++)
				A[i+j] = !A[i+j];
		}
	}
	printf("%d\n", result);
}