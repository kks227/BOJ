#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int, int> P;

int main(){
	int M, N, L, p[100000];
	P a[100000];
	scanf("%d %d %d", &M, &N, &L);
	for(int i=0; i<M; i++)
		scanf("%d", p+i);
	for(int i=0; i<N; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		a[i] = P(x, y);
	}
	sort(p, p+M);
	sort(a, a+N);

	int result = 0;
	for(int i=0, j=0; i<N; i++){
		while(j<M && p[j] < a[i].first) j++;
		if(j>0 && a[i].first-p[j-1]+a[i].second <= L ||
			j<M && p[j]-a[i].first+a[i].second <= L) result++;
	}
	printf("%d\n", result);
}