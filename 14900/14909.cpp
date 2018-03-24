#include <cstdio>
using namespace std;

int main(){
	int val, result = 0;
	while(scanf("%d", &val) > 0) if(val > 0) result++;
	printf("%d\n", result);
}