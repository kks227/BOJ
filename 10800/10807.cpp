#include <cstdio>
using namespace std;

int main(){
	int N, V, cnt[201]={0};
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int n;
		scanf("%d", &n);
		cnt[n+100]++;
	}
	scanf("%d", &V);
	printf("%d\n", cnt[V+100]);
}