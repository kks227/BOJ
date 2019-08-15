#include <cstdio>
using namespace std;

int main(){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if(a+b+c >= 100) puts("OK");
	else if(a < b && a < c) puts("Soongsil");
	else if(b < a && b < c) puts("Korea");
	else puts("Hanyang");
}