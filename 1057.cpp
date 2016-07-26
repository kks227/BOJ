#include <cstdio>
using namespace std;

int main(){
	int N, a, b;
	scanf("%d %d %d", &N, &a, &b);
	int result = 1;
	a--; b--;
	while(1){
		a /= 2;
		b /= 2;
		if(a == b) break;
		result++;
	}
	printf("%d\n", result);
}