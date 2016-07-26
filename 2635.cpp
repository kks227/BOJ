#include <cstdio>
using namespace std;

int main(){
	int N, result, max = 0, a, b, c;
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		int cnt = 0;
		a = N;
		b = i;
		while(b>=0){
			cnt++;
			c = a-b;
			a = b;
			b = c;
		}
		if(cnt > max){
			max = cnt;
			result = i;
		}
	}
	printf("%d\n%d", max+1, N);
	a = N;
	b = result;
	while(b>=0){
		printf(" %d", b);
		c = a-b;
		a = b;
		b = c;
	}
}