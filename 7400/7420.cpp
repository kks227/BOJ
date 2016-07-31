#include <cstdio>
#include <cmath>
#include <stack>
#include <algorithm>
using namespace std;
const double PI = 3.1415926;

struct Point{
	int x, y, p, q;
	Point(): Point(0, 0, 1, 0){}
	Point(int x1, int y1): Point(x1, y1, 1, 0){}
	Point(int x1, int y1, int p1, int q1): x(x1), y(y1), p(p1), q(q1){}
	bool operator <(const Point& O){
		if(1LL*q*O.p != 1LL*p*O.q) return 1LL*q*O.p < 1LL*p*O.q;
		if(x != O.x) return x < O.x;
		return y < O.y;
	}
};

double distance(const Point& A, const Point& B){
	return sqrt(pow(A.x-B.x, 2.0) + pow(A.y-B.y, 2.0));
}

long long ccw(const Point& A, const Point& B, const Point& C){
	return 1LL*(B.x-A.x)*(C.y-A.y) - 1LL*(B.y-A.y)*(C.x-A.x);
}

int main(){
	int N, L;
	scanf("%d %d", &N, &L);
	Point p[1000];
	for(int i=0; i<N; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		p[i] = Point(x, y);
	}
	sort(p, p+N);
	for(int i=1; i<N; i++){
		p[i].p = p[i].x - p[0].x;
		p[i].q = p[i].y - p[0].y;
	}
	sort(p+1, p+N);

	stack<int> S;
	S.push(0);
	S.push(1);
	int next = 2;
	while(next < N){
		while(S.size() >= 2){
			int first, second;
			first = S.top();
			S.pop();
			second = S.top();
			if(ccw(p[second], p[first], p[next]) > 0){
				S.push(first);
				break;
			}
		}
		S.push(next++);
	}

	int H = S.size();
	Point h[1000];
	for(int i=0; i<H; i++){
		h[i] = p[S.top()];
		S.pop();
	}
	double result = 0;
	for(int i=0; i<H; i++){
		int j = (i+1) % H, k = (i+H-1) % H;
		double d1 = distance(h[i], h[j]);
		double d2 = distance(h[i], h[k]);
		result += d1;
		long long dot = 1LL*(h[j].x-h[i].x)*(h[k].x-h[i].x) + 1LL*(h[j].y-h[i].y)*(h[k].y-h[i].y);
		result += L*(PI-acos(dot/d1/d2));
	}
	printf("%.0lf\n", result);
}