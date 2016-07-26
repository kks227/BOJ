#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int V, E;
		scanf("%d %d", &V, &E);
		printf("%d\n", 2-V+E);
	}
}