#include <cstdio>
#include <cmath>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 100000;
typedef pair<double, int> P;

int main(){
	int N, A, wSum = 0;
	P g[MAX];
	scanf("%d %d", &N, &A);
	for(int i = 0; i < N; ++i){
		int x, y;
		scanf("%d %d %d", &x, &y, &g[i].second);
		g[i].first = sqrt(x*x + y*y);
		wSum += g[i].second;
	}
	sort(g, g+N);
	double result = 0, p = -A, q = 0, r = 0;
	for(int i = 0; i < N; ++i){
		int w = g[i].second;
		double d = g[i].first;
		q += w;
		r -= w*d;
		double x[3] = {d, (i == N-1 ? wSum/A : g[i+1].first), -q/(2*p)};
		for(int j = 0; j < 3; ++j){
			if(j == 2 && x[2] < x[0] || x[1] < x[2]) continue;
			result = max(p*x[j]*x[j] + q*x[j] + r, result);
		}
	}
	printf("%.9lf\n", result);
}