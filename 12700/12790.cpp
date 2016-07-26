#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int h[2], m[2], a[2], d[2];
		for(int i=0; i<2; i++)
			scanf("%d %d %d %d", h+i, m+i, a+i, d+i);
		printf("%d\n", max(1, h[0]+h[1]) + max(1, m[0]+m[1])*5 + max(0, a[0]+a[1])*2 + (d[0]+d[1])*2);
	}
}