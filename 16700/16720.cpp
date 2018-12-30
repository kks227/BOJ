#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int main(){
	int N, col[1000], result = INF;
	scanf("%d", &N);
	for(int i = 1; i < N-1; ++i){
		for(int j = 0; j < 4; ++j){
			int b;
			scanf("%1d", &b);
			if(b == 0) col[i] = j;
		}
	}
	for(int i = 0; i < 4; ++i){
		int temp = N + 2;
		for(int j = 1; j < N-1; ++j){
			int k = abs(i-col[j]);
			temp += min(k, 4-k);
		}
		result = min(temp, result);
	}
	printf("%d\n", result);
}