#include <cstdio>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<double, int> P;

inline double distance(double x1, double y1, double x2, double y2){
	return sqrt(pow(x1-x2, 2.0) + pow(y1-y2, 2.0));
}

int main(){
	int N, M = 0;
	char S[101];
	double range[10000];
	scanf("%d %s", &N, S);
	char c[100], x[100], y[100];
	for(int i=0; i<N; i++){
		scanf(" %c %d %d", c+i, x+i, y+i);
		for(int j=0; j<i; j++)
			if(y[i] != y[j]) range[M++] = x[i]-y[i]*(x[j]-x[i])/(1.0*y[j]-y[i]);
	}
	sort(range, range+M);

	vector<int> result;
	for(int i=0; i<=M; i++){
		double xpos;
		if(i == 0) xpos = (M == 0 ? 0 : range[0] - 1000);
		else if(i == M) xpos = range[M-1] + 1000;
		else if(range[i]-range[i-1] > 1e-4) xpos = (range[i-1]+range[i])/2;
		else continue;

		P point[100];
		for(int j=0; j<N; j++)
			point[j] = P((x[j]-xpos)/distance(xpos, 0, x[j], y[j]), j);
		sort(point, point+N);
		bool check = true;
		for(int j=0; j<N; j++){
			if(c[point[j].second] != S[j]){
				check = false;
				break;
			}
		}
		if(check) result.push_back(i);
	}
	printf("%d\n", result.size());
	for(int i: result){
		if(i == 0){
			if(M == 0) puts("* *");
			else printf("* %.4lf\n", range[0]);
		}
		else if(i == M) printf("%.4lf *\n", range[M-1]);
		else printf("%.4lf %.4lf\n", range[i-1], range[i]);
	}
}