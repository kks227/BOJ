#include <cstdio>
using namespace std;

int main(){
	int D, K, fibo[31] = {0, 1};
	scanf("%d %d", &D, &K);
	for(int i=2; i<31; i++)
		fibo[i] = fibo[i-1] + fibo[i-2];
	for(int i=1; ; i++){
		if((K-fibo[D-2]*i)%fibo[D-1] == 0){
			printf("%d\n%d\n", i, (K-fibo[D-2]*i)/fibo[D-1]);
			break;
		}
	}
}