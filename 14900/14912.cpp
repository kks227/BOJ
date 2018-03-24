#include <cstdio>
using namespace std;

int main(){
	int N, D, result = 0;
	scanf("%d %d", &N, &D);
	for(int i=1; i<=N; i++){
		int k = i;
		do{
			if(k%10 == D) result++;
			k /= 10;
		}while(k);
	}
	printf("%d\n", result);
}