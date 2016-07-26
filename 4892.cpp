#include <cstdio>
using namespace std;

int main(){
	for(int i=1; ; i++){
		int n;
		scanf("%d", &n);
		if(n == 0) break;
		n *= 3;
		printf("%d. %s ", i, n%2 ? "odd" : "even");
		n = (n+1)/2;
		n *= 3;
		n /= 9;
		printf("%d\n", n);
	}
}