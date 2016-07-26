#include <cstdio>
using namespace std;

int main(){
	int a[2], l[2];
	scanf("%d %d %d %d", a, l, a+1, l+1);
	int x = l[0]/a[1], y = l[1]/a[0];
	if(l[0]%a[1]) x++;
	if(l[1]%a[0]) y++;
	if(x == y) puts("DRAW");
	else printf("PLAYER %c\n", x>y ? 'A' : 'B');
}