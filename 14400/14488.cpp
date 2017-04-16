#include <cstdio>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<double, double> P;

int main(){
	int N, x[50000], v[50000];
	double T;
	scanf("%d %lf", &N, &T);
	P p[50000];
	for(int i=0; i<N; i++)
		scanf("%d", x+i);
	for(int i=0; i<N; i++)
		scanf("%d", v+i);
	for(int i=0; i<N; i++)
		p[i] = P(x[i]-v[i]*T, x[i]+v[i]*T);
	sort(p, p+N);

	bool result = true;
	double last = p[0].second;
	for(int i=1; i<N; i++){
		if(last < p[i].first){
			result = false;
			break;
		}
		last = min(last, p[i].second);
	}
	printf("%d\n", result);
}