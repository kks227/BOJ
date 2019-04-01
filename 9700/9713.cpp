#include <cstdio>
using namespace std;
const int MAX = 101;

int main(){
	int T, result[MAX] = {0,};
	for(int i = 1; i < MAX; i += 2)
		result[i] = result[i+1] = result[i-1] + i;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		int N;
		scanf("%d", &N);
		printf("%d\n", result[N]);
	}
}