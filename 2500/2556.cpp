#include <cstdio>
using namespace std;

int main(){

	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++)
			putchar('*');
		putchar('\n');
	}

	return 0;
}