#include <cstdio>
using namespace std;

int main(){
	int n, result = 0;
	scanf("%d", &n);
	for(int i=0; i<100; i++)
		for(int j=0; j<100; j++)
			if(i+j == n) result++;
	printf("%d\n", result);
}