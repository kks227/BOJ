#include <cstdio>
using namespace std;

int main(){

	int Ai, sum = 0;
	for(int i=0; i<5; i++){
		scanf("%d", &Ai);
		sum += Ai;
	}
	printf("%d\n", sum);

	return 0;
}