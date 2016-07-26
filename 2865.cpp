#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, M, K;
	double h[100] = {0}, result = 0;
	scanf("%d %d %d", &N, &M, &K);
	for(int i=0; i<M; i++)
		for(int j=0; j<N; j++){
			int p;
			double s;
			scanf("%d %lf", &p, &s);
			p--;
			h[p] = max(h[p], s);
		}
	sort(h, h+N);
	for(int i=0; i<K; i++)
		result += h[N-i-1];
	printf("%.1lf\n", result);
}