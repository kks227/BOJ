#include <cstdio>
#include <cmath>
using namespace std;

long long pow10(int n){
	long long result = 1;
	for(int i=0; i<n; i++)
		result *= 10;
	return result;
}

long long a(int n){
	return n*pow10(n-1);
}

long long func(long long n, int digit){
	long long result = 0;
	if(digit==1){
		for(int i=1; i<=n; i++)
			result += i;
		return result;
	}
	long long power = pow10(digit-1);
	long long q = n % power;
	long long p = n / power;
	result += p*45*a(digit-1);
	for(int i=1; i<p; i++)
		result += i*power;
	result += p*(q+1);
	result += func(q, digit-1);
	return result;
}

int main(){
	int L, U;
	scanf("%d %d", &L, &U);
	if(U==0) puts("0");
	else{
		long long result = func(U, (int)log10(1.0*U)+1);
		if(L>1) result -= func(L-1, (int)log10(L-1.0)+1);
		printf("%lld\n", result);
	}
}