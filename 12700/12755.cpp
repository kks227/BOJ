#include <cstdio>
using namespace std;

int main(){
	int N, p = 1, cnt = 1;
	scanf("%d", &N);
	N--;
	int digit = 1, val = 1;
	while(1){
		if(val==10 || val==100 || val==1000 || val==10000 || val==100000 || val==1000000 || val==10000000) digit++;
		if(N < digit){
			for(int i=N+1; i<digit; i++) val /= 10;
			printf("%d\n", val%10);
			break;
		}
		N -= digit;
		val++;
	}
}