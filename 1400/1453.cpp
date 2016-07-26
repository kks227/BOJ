#include <cstdio>
using namespace std;

int main(){

	int N, n, result = 0;
	bool flag[100] = {0};
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", &n);
		result += flag[n-1];
		flag[n-1] = true;
	}
	printf("%d\n", result);

	return 0;
}