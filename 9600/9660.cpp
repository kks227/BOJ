#include <cstdio>
using namespace std;

int main(){
	long long N;
	scanf("%lld", &N);
	printf("%s\n", (N%7==0 || N%7==2) ? "CY" : "SK");
}