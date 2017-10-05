#include <cstdio>
using namespace std;

int main(){
	int M, N, cnt[10] = {0};
	scanf("%d %d", &M, &N);
	for(int i=M; i<=N; i++){
		int n = i;
		while(n){
			cnt[n%10]++;
			n /= 10;
		}
	}
	for(int i=0; i<10; i++)
		printf("%d ", cnt[i]);
}