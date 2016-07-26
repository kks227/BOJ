#include <cstdio>

int main(){

	int k;
	scanf("%d", &k);
	for(int i=0; i<k; i++)
		printf("1");
	for(int i=1; i<k; i++)
		printf("0");
	printf("\n");
 
    return 0;
}