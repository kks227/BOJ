#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N, M;
		scanf("%d %d", &N, &M);
		printf("%d %d\n", M*2-N, N-M);
	}
}