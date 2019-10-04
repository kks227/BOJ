#include <cstdio>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int MAX = 100000;
const int xoff[4] = {0, 0, 1, -1};
const int yoff[4] = {1, -1, 0, 0};

int main(){
	unordered_map<char, int> C2I;
	C2I['S'] = 0; C2I['J'] = 1; C2I['I'] = 2; C2I['Z'] = 3;
	int N, M, x[MAX], y[MAX], cx = 0, cy = 0;
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; ++i)
		scanf("%d %d", x+i, y+i);
	sort(x, x+N);
	sort(y, y+N);
	long long xSum[MAX+1] = {0,}, ySum[MAX+1] = {0,};
	for(int i = 0; i < N; ++i){
		xSum[i+1] = xSum[i] + x[i];
		ySum[i+1] = ySum[i] + y[i];
	}
	getchar();
	for(int i = 0; i < M; ++i){
		int d = C2I[getchar()];
		cx += xoff[d]; cy += yoff[d];
		int a = lower_bound(x, x+N, cx) - x, b = lower_bound(y, y+N, cy) - y;
		long long ta = 1LL*a*cx - xSum[a] + xSum[N]-xSum[a] - 1LL*(N-a)*cx;
		long long tb = 1LL*b*cy - ySum[b] + ySum[N]-ySum[b] - 1LL*(N-b)*cy;
		printf("%lld\n", ta + tb);
	}
}