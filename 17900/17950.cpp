#include <cstdio>
using namespace std;
const int MOD = 1000000007;
const int MAX = 1000000;

int main(){
	int H, x, c[MAX], result = 0;
	scanf("%d %d", &H, &x);
	for(int i = 0; i < H; ++i)
		scanf("%d", c+i);
	for(int i = H-1; i >= 0; --i)
		result = 1LL * (result + c[i]) * x % MOD;
	printf("%d\n", result);
}