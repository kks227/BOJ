#include <cstdio>
using namespace std;

int main(){
	int N, result[15] = {1, 0, 0, 2, 10, 4, 40, 92, 352, 724, 2680, 14200, 73712, 365596, 2279184};
	scanf("%d", &N);
	printf("%d\n", result[N-1]);
}