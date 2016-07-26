#include <cstdio>
using namespace std;

int gcd(int a, int b){
	int temp;
	while(b){
		temp = a%b;
		a = b;
		b = temp;
	}
	return a;
}

int main(){

	int N, a, b;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d %d", &a, &b);
		printf("%d\n", a*b/gcd(a, b));
	}

    return 0;
}