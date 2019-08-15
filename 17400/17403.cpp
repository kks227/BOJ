#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1000;

struct Point{
	int x, y, p, q, pNum;
	Point(): Point(0, 0, 1, 0, -1){}
	Point(int x1, int y1, int pNum1): Point(x1, y1, 1, 0, pNum1){}
	Point(int x1, int y1, int p1, int q1, int pNum1): x(x1), y(y1), p(p1), q(q1), pNum(pNum1){}
	bool operator <(const Point& O){
		if(q*O.p != p*O.q) return q*O.p < p*O.q;
		if(x != O.x) return x < O.x;
		return y < O.y;
	}
};

int ccw(const Point& A, const Point& B, const Point& C){
	return (B.x-A.x)*(C.y-A.y) - (B.y-A.y)*(C.x-A.x);
}



int main(){
	int N, x[MAX], y[MAX];
	scanf("%d", &N);
	vector<Point> p;
	for(int i = 0; i < N; ++i){
		scanf("%d %d", x+i, y+i);
		p.push_back(Point(x[i], y[i], i));
	}

	int result[MAX] = {0,}, M = N;
	for(int k = 1; M > 2; ++k){
		sort(p.begin(), p.end());
		for(int i = 1; i < M; ++i){
			p[i].p = p[i].x - p[0].x;
			p[i].q = p[i].y - p[0].y;
		}
		sort(p.begin()+1, p.end());

		vector<int> H;
		H.push_back(0);
		H.push_back(1);
		int next = 2;
		while(next < M){
			while(H.size() >= 2){
				int first = H.back(); H.pop_back();
				int second = H.back();
				if(ccw(p[second], p[first], p[next]) > 0){
					H.push_back(first);
					break;
				}
			}
			H.push_back(next++);
		}
		if(H.size() <= 2) break;

		bool efface[MAX] = {false,};
		for(int i: H)
			efface[i] = true;
		vector<Point> pNew;
		for(int i = 0; i < M; ++i){
			if(efface[i]) result[p[i].pNum] = k;
			else pNew.push_back(Point(p[i].x, p[i].y, p[i].pNum));
		}
		p = pNew;
		M -= H.size();
	}

	for(int i = 0; i < N; ++i)
		printf("%d ", result[i]);
}