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
		if(y != O.y) return y < O.y;
		return x < O.x;
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

// A와 B의 거리가 result보다 크면 result를 갱신, r1=P, r2=Q로 갱신
void getGreater(long long& result, int& r1, int& r2, const Point& A, const Point& B, int P, int Q){
	long long dist = square(A, B);
	if(result < dist){
		result = dist;
		r1 = P;
		r2 = Q;
	}
}



int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N;
		scanf("%d", &N);
		Point p[200000];
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
		int P = 0, Q = 1, next = 2, maxY = p[1].y;
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
			// Q는 컨벡스헐에서 가장 위에 있는 점의 번호
			if(p[next].y > maxY || p[next].y == maxY && p[next].x > p[Q].x){
				maxY = p[next].y;
				Q = S.size();
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
		long long result = square(p[hull[P]], p[hull[Q]]);
		int r1 = P, r2 = Q;
		IVector Pv(-1, 0);
		// P, Q를 캘리퍼스 축으로 시작하여 한바퀴 돌리며 최대거리 찾기
		for(int i=0; i<hSize; i++){
			int Pnext = (P+hSize-1) % hSize;
			int Qnext = (Q+hSize-1) % hSize;
			double Pa = cosin(Pv, p[hull[Pnext]]-p[hull[P]]);
			double Qa = cosin(-Pv, p[hull[Qnext]]-p[hull[Q]]);
			// 실수오차 가능성을 고려하여 근처의 가능한 점 쌍을 다 시도해 봄
			getGreater(result, r1, r2, p[hull[Pnext]], p[hull[Q]], Pnext, Q);
			getGreater(result, r1, r2, p[hull[P]], p[hull[Qnext]], P, Qnext);
			if(Pa >= Qa){
				Pv = p[hull[Pnext]] - p[hull[P]];
				P = Pnext;
			}
			else{
				Pv = p[hull[Q]] - p[hull[Qnext]];
				Q = Qnext;
			}
			// 실수 오차가 없을 경우, 알고리즘상으로는 이 부분만 갱신해줘도 됨
			getGreater(result, r1, r2, p[hull[P]], p[hull[Q]], P, Q);
		}
		printf("%d %d %d %d\n", p[hull[r1]].x, p[hull[r1]].y, p[hull[r2]].x, p[hull[r2]].y);
	}
}