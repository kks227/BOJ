#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 100;

int main(){
	int R, C, L, K, x[MAX], y[MAX], result = 0;
	scanf("%d %d %d %d", &R, &C, &L, &K);
	for(int i = 0; i < K; ++i)
		scanf("%d %d", x+i, y+i);
	for(int i = 0; i < K; ++i){
		int x1 = x[i], x2 = x[i]+L;
		for(int j = 0; j < K; ++j){
			int y1 = y[j], y2 = y[j]+L, cnt = 0;
			for(int k = 0; k < K; ++k)
				if(x1 <= x[k] && x[k] <= x2 && y1 <= y[k] && y[k] <= y2) ++cnt;
			result = max(cnt, result);
		}
	}
	printf("%d\n", K-result);
}