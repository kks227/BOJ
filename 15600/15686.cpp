#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int N, M, H, K, map[50][50], hr[2500], hc[2500], cr[13], cc[13], used[13], result;

void backtrack(int k, int m){
	if(m == M){
		int sum = 0;
		for(int i=0; i<H; i++){
			int temp = INF;
			for(int j=0; j<M; j++)
				temp = min(abs(hr[i]-cr[used[j]]) + abs(hc[i]-cc[used[j]]), temp);
			sum += temp;
		}
		result = min(sum, result);
		return;
	}
	if(K-k < M-m) return;

	backtrack(k+1, m);
	used[m] = k;
	backtrack(k+1, m+1);
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			scanf("%d", &map[i][j]);
			if(map[i][j] == 1){
				hr[H] = i;
				hc[H] = j;
				H++;
			}
			else if(map[i][j] == 2){
				cr[K] = i;
				cc[K] = j;
				K++;
			}
		}
	}
	result = INF;
	backtrack(0, 0);
	printf("%d\n", result);
}