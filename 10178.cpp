#include <cstdio>
using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int C, B;
		scanf("%d %d", &C, &B);
		printf("You get %d piece(s) and your dad gets %d piece(s).\n", C/B, C%B);
	}
}