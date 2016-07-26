#include <cstdio>
using namespace std;

int main(){
	int N, cnt[10000] = {0};
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int n;
		scanf("%d", &n);
		cnt[n-1]++;
	}
	for(int i=0; i<10000; i++)
		for(int j=0; j<cnt[i]; j++)
			printf("%d\n", i+1);
}