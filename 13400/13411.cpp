#include <cstdio>
#include <cmath>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<double, int> P;

int main(){
	int N;
	P p[100000];
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int x, y, v;
		scanf("%d %d %d", &x, &y, &v);
		p[i] = P(sqrt(x*x+y*y)/v, i+1);
	}
	sort(p, p+N);
	for(int i=0; i<N; i++)
		printf("%d\n", p[i].second);
}