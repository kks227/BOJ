#include <cstdio>
using namespace std;

int main(){
	int N, cnt = 0;
	scanf("%d", &N);
	while(N >= 10){
		int next = 1;
		while(N){
			next *= N%10;
			N /= 10;
		}
		N = next;
		cnt++;
	}
	printf("%d\n", cnt);
}