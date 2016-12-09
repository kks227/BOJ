#include <cstdio>
using namespace std;

int Rev(int n){
	int result = 0;
	while(n){
		result *= 10;
		result += n%10;
		n /= 10;
	}
	return result;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int X, Y;
		scanf("%d %d", &X, &Y);
		printf("%d\n", Rev(Rev(X) + Rev(Y)));
	}
}