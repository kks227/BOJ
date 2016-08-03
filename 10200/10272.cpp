#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const double INF = 1000000000;

int N;
P pos[512];
bool visited[512][512];
double dp[512][512];

inline double d2(P &p, P &q){
	return sqrt(pow(p.first-q.first, 2.0) + pow(p.second-q.second, 2.0));
}

double jeongeun(int a, int b){
	double &ret = dp[a][b];
	if(visited[a][b]) return ret;
	visited[a][b] = true;
	if(a == N-1 || b == N-1) return ret = d2(pos[a], pos[b]);

	int next = max(a, b) + 1;
	ret = INF;
	if(a < N-1) ret = min(ret, jeongeun(next, b) + d2(pos[a], pos[next]));
	if(b < N-1) ret = min(ret, jeongeun(a, next) + d2(pos[b], pos[next]));
	return ret;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		scanf("%d", &N);
		for(int i=0; i<N; i++){
			int x, y;
			scanf("%d %d", &x, &y);
			pos[i] = P(x, y);
		}
		sort(pos, pos+N);
		memset(visited, 0, sizeof(visited));
		printf("%.6lf\n", jeongeun(0, 0));
	}
}