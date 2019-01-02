#include <cstdio>
#include <cmath>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 30000;
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

class DynamicConvexHull{
public:
	int input(){
		scanf("%d %d", &N, &T);
		for(int i = 0; i < N; ++i)
			scanf("%d %d %d %d", x0+i, y0+i, dx+i, dy+i);
		return T;
	}

	long long getLongest(int t){
		Point p[MAX];
		for(int i = 0; i < N; ++i)
			p[i] = Point(x0[i] + dx[i]*t, y0[i] + dy[i]*t);
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
		IVector pivotVec(-1, 0);
		for(int i = 0; i < hSize*2; ++i){
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
			result = max(d2(p[hull[pCurr]], p[hull[qCurr]]), result);
		}

		return result;
	}

private:
	int N, T, x0[MAX], y0[MAX], dx[MAX], dy[MAX];
};



int main(){
	DynamicConvexHull Solver;
	int T = Solver.input();
	int lo = 0, hi = T;
	while(hi-lo >= 3){
		int p = (lo*2 + hi)/3, q = (lo + hi*2)/3;
		long long pVal = Solver.getLongest(p), qVal = Solver.getLongest(q);
		if(pVal <= qVal) hi = q;
		else lo = p;
	}
	int res1 = -1;
	long long res2 = INF;
	for(int i = lo; i <= hi; ++i){
		long long temp = Solver.getLongest(i);
		if(res2 > temp){
			res1 = i;
			res2 = temp;
		}
	}
	printf("%d\n%lld\n", res1, res2);
}