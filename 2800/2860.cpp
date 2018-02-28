#include <cstdio>
using namespace std;

int main(){
	char P[12];
	scanf("%s", P);

	long long a = P[0]-'0', b = 1;
	for(int i=2; P[i]; i++){
		a = a*10 + P[i]-'0';
		b *= 10;
	}
	long long p = a, q = b;
	while(q){
		long long r = p % q;
		p = q;
		q = r;
	}
	a /= p; b /= p;

	long long result[5] = {0}, C = 0;
	for(int i=5; i>1; i--){
		result[i-1] = (a-b-C)/(i-1);
		b -= result[i-1];
		C += i*result[i-1];
	}
	result[0] = b;
	for(int i=0; i<5; i++)
		printf("%lld ", result[i]);
}