#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <algorithm>
using namespace std;
typedef pair<double, double> P;

int main(){
	int N, M = 0, R, X, Y, VX, VY, always = 0;
	scanf("%d %d %d %d %d %d", &N, &R, &X, &Y, &VX, &VY);
	P p[50000];
	for(int i=0; i<N; i++){
		int x, y, vx, vy;
		scanf("%d %d %d %d", &x, &y, &vx, &vy);
		int dvx = vx-VX, dvy = vy-VY, dx = x-X, dy = y-Y;
		int a = dvx*dvx + dvy*dvy;
		int b = 2*(dvx*dx + dvy*dy);
		int c = dx*dx + dy*dy - R*R;
		if(a == 0){
			if(b == 0) always += (c <= 0);
			else if(1LL*b*c >= 0) p[M++] = P(0.0, -1.0*c/b);
		}
		else{
			long long D = 1LL*b*b - 4LL*a*c;
			if(D >= 0){
				double t1 = (-b-sqrt(D))/2/a, t2 = (-b+sqrt(D))/2/a;
				if(t2 >= 0) p[M++] = P(max(0.0, t1), t2);
			}
		}
	}
	sort(p, p+M);

	int result = 0;
	priority_queue<double, vector<double>, greater<double>> PQ;
	for(int i=0; i<M; i++){
		PQ.push(p[i].second);
		while(!PQ.empty() && PQ.top() < p[i].first) PQ.pop();
		result = max(result, (int)PQ.size());
	}
	printf("%d\n", result + always);
}