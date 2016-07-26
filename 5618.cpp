#include <cstdio>
using namespace std;

int gcd(int m, int n){
	int r;
	while(n){
		r = m%n;
		m = n;
		n = r;
	}
	return m;
}

void print(int n){
	for(int i=1; i<=n; i++)
		if(n%i == 0) printf("%d\n", i);
}

int main(){

	int n, a, b, c;
	scanf("%d", &n);
	if(n == 2){
		scanf("%d %d", &a, &b);
		print(gcd(a, b));
	}
	else{
		scanf("%d %d %d", &a, &b, &c);
		print(gcd(gcd(a, b), c));
	}

	return 0;
}