#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int a, m;
	scanf("%d %d", &a, &m);
	int result = m;
	for(int i=1; i<m; i++)
		if(a*i%m == 1) result = min(result, i);
	printf("%d\n", result);
}