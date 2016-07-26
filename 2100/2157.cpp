#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int IMPOSSIBLE = -20000;
int N, M, point[300][300], cache[300][300];
vector<int> adj[300];

int maxPoint(int pos, int limit){
	int &ret = cache[pos][limit];
	if(ret != -1) return ret;
	if(pos == N-1) return ret = 0;
	if(limit == 1) return ret = point[pos][N-1]?point[pos][N-1]:IMPOSSIBLE;
	ret = IMPOSSIBLE;
	for(int next: adj[pos]){
		int temp = maxPoint(next, limit-1);
		if(temp != IMPOSSIBLE) ret = max(ret, temp+point[pos][next]);
	}
	return ret;
}

int main(){
	int K;
	scanf("%d %d %d", &N, &M, &K);
	for(int i=0; i<K; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if(a<b){
			adj[a-1].push_back(b-1);
			point[a-1][b-1] = max(point[a-1][b-1], c);
		}
	}
	memset(cache, -1, sizeof(cache));
	printf("%d\n", maxPoint(0, M-1));
}