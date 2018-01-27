#include <cstdio>
using namespace std;

int main(){
	int N, M, result = 0, pos = 0;
	scanf("%d %d", &N, &M);
	for(int i=1; i<M; i++){
		pos += N;
		if(pos%M) result++;
	}
	printf("%d\n", result);
}