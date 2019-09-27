#include <cstdio>
using namespace std;

int main(){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	for(int i = 1; i <= c; ++i){
		if(i%a == 0 && i%b == 0) puts("FizzBuzz");
		else if(i%a == 0) puts("Fizz");
		else if(i%b == 0) puts("Buzz");
		else printf("%d\n", i);
	}
}