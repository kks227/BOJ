#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++){
		int a[3];
		scanf("%d %d %d", a, a+1, a+2);
		sort(a, a+3);
		printf("Case #%d: ", t);
		if(a[0]+a[1] <= a[2]) puts("invalid!");
		else if(a[0] == a[1] && a[1] == a[2]) puts("equilateral");
		else if(a[0] == a[1] || a[1] == a[2]) puts("isosceles");
		else puts("scalene");
	}
}