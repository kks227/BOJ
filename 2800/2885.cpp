#include <cstdio>
using namespace std;

int main(){
	int K, pow = 1, cnt = 0;
	scanf("%d", &K);
	while(pow < K) pow *= 2;
	printf("%d ", pow);
	while(K != pow){
		cnt++;
		pow /= 2;
		if(K == pow) break;
		if(K > pow) K -= pow;
	}
	printf("%d\n", cnt);
}