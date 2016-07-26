#include <cstdio>
using namespace std;

int main(){

	int P, K, prev, curr, result;
	scanf("%d", &P);
	for(int t=0; t<P; t++){
		scanf("%d", &K);
		result = prev = 0;
		for(int i=0; i<15; i++){
			scanf("%d", &curr);
			if(prev < curr) result++;
			prev = curr;
		}
		printf("%d %d\n", K, result);
	}

	return 0;
}