#include <cstdio>
using namespace std;

int main(){
	int L, P;
	scanf("%d %d", &L, &P);
	for(int i=0; i<5; i++){
		int N;
		scanf("%d", &N);
		printf("%d ", N-L*P);
	}
}