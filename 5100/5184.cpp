#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 200;

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t){
		int N, L, R;
		double p[MAX], result = 0;
		scanf("%d %d %d", &L, &R, &N);
		for(int i = 0; i < N; ++i)
			scanf("%lf", p+i);
		sort(p, p+N);
		for(int i = 0; i < L; ++i)
			result += p[N-i-1];
		for(int i = L; i < R; ++i)
			result += max(p[N-i-1], 1-p[N-i-1]);
		for(int i = R; i < N; ++i)
			result += 1-p[N-i-1];
		printf("Data Set %d:\n%.2lf\n", t, result);
	}
}