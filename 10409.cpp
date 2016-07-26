#include <cstdio>
using namespace std;

int main(){

	int T, N, current, sum = 0, result = 0;
	scanf("%d %d", &N, &T);
	for(int i=0; i<N; i++){
		scanf("%d", &current);
		sum += current;
		if(sum <= T) result++;
	}
	printf("%d\n", result);

	return 0;
}