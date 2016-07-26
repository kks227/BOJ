#include <cstdio>
using namespace std;

int main(){

	long long S, i;
	scanf("%lld", &S);
	for(i=0; ; i++){
		if(i%2 && (i+1)/2*i > S) break;
		if(i/2*(i+1) > S) break;
	}
	printf("%lld\n", i-1);

	return 0;
}