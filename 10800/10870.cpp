#include <cstdio>
using namespace std;

int main(){
	int N, a=0, b=1, c;
	scanf("%d", &N);
	for(int i=2; i<=N; i++){
		c = a+b;
		a = b;
		b = c;
	}
	printf("%d\n", N?b:0);
}