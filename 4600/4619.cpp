#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	while(1){
		int B, N;
		scanf("%d %d", &B, &N);
		if(B == 0) break;

		double p = pow(B, 1.0/N);
		int A1 = p, A2 = A1+1;
		long long B1 = pow(A1, N), B2 = pow(A2, N);
		printf("%d\n", (abs(B-B1) <= abs(B-B2) ? A1 : A2));
	}
}