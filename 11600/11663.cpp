#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, M, p[100000];
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++)
		scanf("%d", p+i);
	sort(p, p+N);
	for(int i=0; i<M; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", upper_bound(p, p+N, b) - lower_bound(p, p+N, a));
	}
}