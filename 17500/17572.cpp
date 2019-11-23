#include <cstdio>
#include <cmath>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 100;
typedef pair<double, int> P;

int main(){
	int N;
	double T;
	P p[MAX];
	scanf("%lf %d", &T, &N);
	for(int i = 0; i < N; ++i){
		int d, s;
		scanf("%d %d", &d, &s);
		p[i] = P(s*2*acos(-1), d);
	}
	sort(p, p+N);
	int result = 0;
	for(int i = 0; i < N && T >= p[i].first; ++i){
		int temp = min((int)(T/p[i].first), p[i].second);
		result += temp;
		T -= p[i].first * temp;
	}
	printf("%d\n", result);
}