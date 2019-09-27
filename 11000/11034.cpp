#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int a, b, c;
	while(scanf("%d %d %d", &a, &b, &c) > 0)
		printf("%d\n", max(b-a, c-b)-1);
}