#include <cstdio>
using namespace std;

int main(){

	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if(a==60 && b==60 && c==60) puts("Equilateral");
	else if(a==b || b==c || c==a) puts("Isosceles");
	else if(a+b+c==180) puts("Scalene");
	else puts("Error");

	return 0;
}