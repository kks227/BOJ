#include <cstdio>
using namespace std;

int main(){

	int H, P;
	while(1){
		scanf("%d %d", &H, &P);
		if(feof(stdin)) break;
		printf("%.2f\n", H*1.0/P);
	}

	return 0;
}