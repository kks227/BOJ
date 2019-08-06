#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAX = 16;
const int MAX_S = 1<<MAX;

inline double distance(double x1, double y1, double x2, double y2){
	return sqrt(pow(x1-x2, 2.0) + pow(y1-y2, 2.0));
}

int N;
double x[MAX], y[MAX], dp[MAX][MAX_S];

double tsp(int curr, int visited){
	double &ret = dp[curr][visited];
	if(ret >= 0) return ret;
	if(visited == (1<<N)-1) return ret = distance(x[curr], y[curr], x[0], y[0]);

	for(int next = 0; next < N; ++next){
		if(visited & 1<<next) continue;
		double temp = tsp(next, visited | 1<<next) + distance(x[curr], y[curr], x[next], y[next]);
		if(ret < 0 || ret > temp) ret = temp;
	}
	return ret;
}

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%lf %lf", x+i, y+i);
		fill(dp[i], dp[i]+MAX_S, -1);
	}
	printf("%.8lf\n", tsp(0, 1));
}