#include <cstdio>
using namespace std;

int main(){
	int N, result = 0, p = 1, cnt = 1;
	scanf("%d", &N);
	while(N >= p*10LL){
		result = result + p*9*cnt;
		cnt++;
		p *= 10;
	}
	result = result + (N-p+1)*cnt;
	printf("%d\n", result);
}