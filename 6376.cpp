#include <cstdio>
using namespace std;

int main(){
	puts("n e");
	puts("- -----------");
	puts("0 1");
	puts("1 2");
	puts("2 2.5");
	double result = 2.5;
	int fact = 2;
	for(int i=3; i<=9; i++){
		fact *= i;
		result += 1.0/fact;
		printf("%d %.9lf\n", i, result);
	}
}