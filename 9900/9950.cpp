#include <cstdio>
using namespace std;

int main(){
	while(1){
		int a[3];
		scanf("%d %d %d", a, a+1, a+2);
		if(a[0] == 0 && a[1] == 0) break;
		if(a[0] == 0) printf("%d %d %d\n", a[2]/a[1], a[1], a[2]);
		else if(a[1] == 0) printf("%d %d %d\n", a[0], a[2]/a[0], a[2]);
		else printf("%d %d %d\n", a[0], a[1], a[0]*a[1]);
	}
}