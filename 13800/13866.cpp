#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int n[4];
	for(int i=0; i<4; i++)
		scanf("%d", n+i);
	sort(n, n+4);
	printf("%d\n", abs(n[0]+n[3]-n[1]-n[2]));
}