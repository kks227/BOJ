#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		long long X;
		scanf("%lld", &X);
		double S = sqrt(X);
		printf("%d ", S == (int)S);
	}
}