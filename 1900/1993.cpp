#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAX_N = 31;
const int MAX_SCORE = 200;
const int MAX = MAX_N * MAX_SCORE;
const double INF = 1e18;

inline double dist(int x1, int y1, int x2, int y2){ return sqrt(pow(x1-x2, 2.0) + pow(y1-y2, 2.0)); }

int N, x[MAX_N], y[MAX_N], score[MAX_N];
double dp[MAX_N+1][MAX+1];

double race(int pos, int s){
	double &ret = dp[pos][s];
	if(ret != -1) return ret;
	if(pos == 0) return ret = (s > 0 ? INF : 0);

	ret = INF;
	for(int i = 0; i < pos; ++i)
		ret = min(race(i, max(s-score[i], 0)) + dist(x[pos], y[pos], x[i], y[i]), ret);
	return ret;
}

int main(){
	for(int t = 1; ; ++t){
		scanf("%d", &N);
		if(N == 0) break;
		printf("Race %d\n", t);

		for(int i = 0; i < N; ++i)
			scanf("%d %d %d", x+i+1, y+i+1, score+i+1);
		x[0] = y[0] = score[0] = x[N+1] = y[N+1] = score[N+1] = 0;
		for(int i = 0; i < N+2; ++i)
			fill(dp[i], dp[i] + MAX+1, -1);

		while(1){
			char name[61];
			int d;
			scanf("%s %d", name, &d);
			if(name[0] == '#') break;

			for(int i = MAX; ; --i){
				if(race(N+1, i) <= d){
					printf("%s: %d\n", name, i);
					break;
				}
			}
		}
	}
}