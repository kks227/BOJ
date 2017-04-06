#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int K;
		scanf("%d", &K);
		printf("%d\n", (1<<K)-1);
	}
}