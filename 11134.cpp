#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N, C;
		scanf("%d %d", &N, &C);
		printf("%d\n", N/C + (N%C>0));
	}
}