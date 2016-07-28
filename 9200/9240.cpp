#include <cstdio>
#include <cmath>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> IVector;

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

long long square(const Point& A, const Point& B){
	return 1LL*(A.x-B.x)*(A.x-B.x) + 1LL*(A.y-B.y)*(A.y-B.y);
}

long long ccw(const Point& A, const Point& B, const Point& C){
	return 1LL*(B.x-A.x)*(C.y-A.y) - 1LL*(B.y-A.y)*(C.x-A.x);
}

double length(const IVector& A){
	return sqrt(1LL*A.first*A.first + 1LL*A.second*A.second);
}

const IVector operator -(const IVector& A){
	return IVector(-A.first, -A.second);
}

const IVector operator -(const Point& A, const Point& B){
	return IVector(A.x-B.x, A.y-B.y);
}

double cosin(const IVector& A, const IVector& B){
	return (1LL*A.first*B.first + 1LL*A.second*B.second) / length(A) / length(B);
}



int main(){
	int N;
	scanf("%d", &N);
	Point p[100000];
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
	int P = 0, Q = 1, next = 2, maxX = p[1].x;
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
		if(p[next].x > maxX || p[next].x == maxX && p[next].y > p[Q].y){
			maxX = p[next].x;
			Q = next;
		}
		S.push(next++);
	}
	vector<int> hull;
	while(!S.empty()){
		hull.push_back(S.top());
		S.pop();
	}
	reverse(hull.begin(), hull.end());

	int hSize = hull.size();
	for(int i=0; i<hSize; i++){
		if(hull[i] == Q){
			Q = i;
			break;
		}
	}
	long long result = square(p[hull[P]], p[hull[Q]]);
	IVector Pv(0, -1);
	for(int i=0; i<hSize; i++){
		int Pnext = (P+hSize-1) % hSize;
		int Qnext = (Q+hSize-1) % hSize;
		double Pa = cosin(Pv, p[hull[Pnext]]-p[hull[P]]);
		double Qa = cosin(-Pv, p[hull[Qnext]]-p[hull[Q]]);
		if(Pa >= Qa){
			Pv = p[hull[Pnext]] - p[hull[P]];
			P = Pnext;
		}
		else{
			Pv = p[hull[Q]] - p[hull[Qnext]];
			Q = Qnext;
		}
		result = max(result, square(p[hull[P]], p[hull[Q]]));
	}
	printf("%.6lf\n", sqrt(result));
}