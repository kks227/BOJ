#include <cstdio>
#include <cmath>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

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

long long ccw(const Point& A, const Point& B, const Point& C){
	return 1LL*(B.x-A.x)*(C.y-A.y) - 1LL*(B.y-A.y)*(C.x-A.x);
}

int main(){
	int N, Px, Py;
	scanf("%d %d %d", &N, &Px, &Py);
	Point jail(Px, Py);
	vector<Point> p;
	for(int i=0; i<N; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		p.push_back(Point(x, y));
	}

	int result = 0;
	while(N > 2){
		sort(p.begin(), p.end());
		for(int i=1; i<N; i++){
			p[i].p = p[i].x - p[0].x;
			p[i].q = p[i].y - p[0].y;
		}
		sort(p.begin()+1, p.end());

		// 컨벡스 헐 뽑기
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

		// 컨벡스 헐에 속하는 점들을 표시해두는 동시에, 해당 껍질이 감옥을 포함하는지 확인
		bool sign[2] = {0}, efface[1000] = {0};
		S.push(0);
		while(S.size() > 1){
			int A = S.top();
			S.pop();
			int B = S.top();
			if(ccw(p[A], p[B], jail) >= 0) sign[1] = true;
			else sign[0] = true;
			efface[A] = true;
		}
		// 컨벡스 헐 위의 반직선 AB와 AJ(Jail)의 외적의 부호가 모두 같아야 포함됨
		if(sign[0] && sign[1]) break;

		result++;
		vector<Point> inner;
		for(int i=0; i<N; i++){
			if(!efface[i]) inner.push_back(Point(p[i].x, p[i].y));
		}
		p = inner;
		N = p.size();
	}
	printf("%d\n", result);
}