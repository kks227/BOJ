#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 10000;
const int INF = 1e9 + 1;

int main(){
	int N, H, p[MAX], d[MAX], ind[MAX] = {0,}, val[MAX] = {0,};
	scanf("%d %d", &N, &H);
	for(int i = 0; i < N; ++i){
		scanf("%d %d", p+i, d+i);
		if(--p[i] >= 0) ++ind[p[i]];
	}
	fill(val, val+N, INF);
	queue<int> Q;
	for(int i = 0; i < N; ++i){
		if(ind[i] == 0){
			Q.push(i);
			val[i] = H;
		}
	}
	int result = 0;
	while(!Q.empty()){
		int curr = Q.front(); Q.pop();
		if(p[curr] < 0) break;
		int next = p[curr];
		result += max(d[curr] - val[curr], 0);
		val[next] = min(max(val[curr] - d[curr], 0), val[next]);
		if(--ind[next] == 0) Q.push(next);
	}
	printf("%d\n", result);
}