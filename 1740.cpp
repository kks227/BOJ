#include <cstdio>
using namespace std;

int main(){

	long long N;
	scanf("%lld", &N);
	long long pow2 = 1, pow3 = 1;
	int exp2 = 0;
	while(pow2*2 <= N){
		pow2 *= 2;
		pow3 *= 3;
		exp2++;
	}
	long long result = 0;
	for(; exp2>=0; exp2--){
		if(N%(pow2*2) >= pow2) result += pow3;
		pow3 /= 3;
		pow2 /= 2;
	}
	printf("%lld\n", result);

	return 0;
}