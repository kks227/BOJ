#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	while(1){
		int a[3];
		scanf("%d %d %d", a, a+1, a+2);
		sort(a, a+3);
		if(a[0] == 0) break;

		if(a[0]+a[1] <= a[2]) puts("Invalid");
		else if(a[0] == a[1] && a[1] == a[2]) puts("Equilateral");
		else if(a[0] == a[1] || a[1] == a[2]) puts("Isosceles");
		else puts("Scalene");
	}
}