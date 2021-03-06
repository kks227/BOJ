#include <cstdio>
#include <cmath>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 200000;
const long long INF = 1e18;
typedef pair<int, int> IVector;

class Point{
public:
	int x, y, p, q;
	Point(): Point(0, 0, 1, 0){}
	Point(int x1, int y1): Point(x1, y1, 1, 0){}
	Point(int x1, int y1, int p1, int q1): x(x1), y(y1), p(p1), q(q1){}
	bool operator <(const Point& O){
		if(1LL*q*O.p != 1LL*p*O.q) return 1LL*q*O.p < 1LL*p*O.q;
		if(y != O.y) return y < O.y;
		return x < O.x;
	}
};

long long d2(const Point& A, const Point& B){
	return 1LL*(A.x-B.x)*(A.x-B.x) + 1LL*(A.y-B.y)*(A.y-B.y);
}

long long cross(const IVector& A, const IVector& B){
	return 1LL*A.first*B.second - 1LL*A.second*B.first;
}

long long ccw(const Point& A, const Point& B, const Point& C){
	return 1LL*(B.x-A.x)*(C.y-A.y) - 1LL*(B.y-A.y)*(C.x-A.x);
}

const IVector operator -(const IVector& A){
	return IVector(-A.first, -A.second);
}

const IVector operator -(const Point& A, const Point& B){
	return IVector(A.x-B.x, A.y-B.y);
}

class ConvexHull{
public:
	void input(){
		scanf("%d", &N);
		for(int i = 0; i < N; ++i)
			scanf("%d %d", &p[i].x, &p[i].y);
	}

	void output(){
		sort(p, p+N);
		for(int i = 1; i < N; ++i){
			p[i].p = p[i].x - p[0].x;
			p[i].q = p[i].y - p[0].y;
		}
		sort(p+1, p+N);

		stack<int> S;
		S.push(0);
		S.push(1);
		int pCurr = 0, qCurr = 1, next = 2, maxY = p[1].y;
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
			if(p[next].y > maxY || p[next].y == maxY && p[next].x > p[qCurr].x){
				maxY = p[next].y;
				qCurr = S.size();
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
		long long result = d2(p[hull[pCurr]], p[hull[qCurr]]);
		int r1 = pCurr, r2 = qCurr;
		IVector pivotVec(-1, 0);
		for(int i = 0; i < hSize; ++i){
			int pNext = (pCurr+hSize-1) % hSize;
			int qNext = (qCurr+hSize-1) % hSize;
			IVector pVec = p[hull[pNext]] - p[hull[pCurr]];
			IVector qVec = p[hull[qNext]] - p[hull[qCurr]];
			if(cross(pVec, qVec) >= 0){
				pivotVec = pVec;
				pCurr = pNext;
			}
			else{
				pivotVec = -qVec;
				qCurr = qNext;
			}

			long long d = d2(p[hull[pCurr]], p[hull[qCurr]]);
			if(result < d){
				result = d;
				r1 = pCurr;
				r2 = qCurr;
			}
		}

		printf("%d %d %d %d\n", p[hull[r1]].x, p[hull[r1]].y, p[hull[r2]].x, p[hull[r2]].y);
	}

private:
	int N;
	Point p[MAX];
};



int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		ConvexHull CH;
		CH.input();
		CH.output();
	}
}