#include <cstdio>
using namespace std;

int main(){
	int N, n, cnt=0;
	scanf("%d", &N);
	for(int i=0; i<5; i++){
		scanf("%d", &n);
		cnt += N==n;
	}
	printf("%d\n", cnt);
}