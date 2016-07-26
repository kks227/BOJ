#include <cstdio>
using namespace std;

int main(){
	int N, M, L, cnt[1000] = {0}, pos = 0, result = 0;
	scanf("%d %d %d", &N, &M, &L);
	while(++cnt[pos] < M){
		if(cnt[pos] % 2) pos = (pos+L)%N;
		else pos = (pos-L+N)%N;
		result++;
	}
	printf("%d\n", result);
}