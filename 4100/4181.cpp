#include <cstdio>
#include <cmath>
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

int main(){
	int N, cnt = 0;
	scanf("%d", &N);
	Point p[100000];
	for(int i=0; i<N; i++){
		int x, y;
		char c;
		scanf("%d %d %c", &x, &y, &c);
		if(c == 'Y') p[cnt++] = Point(x, y);
	}
	N = cnt;

	sort(p, p+N);
	for(int i=1; i<N; i++){
		p[i].p = p[i].x - p[0].x;
		p[i].q = p[i].y - p[0].y;
	}
	sort(p+1, p+N);
	// 시작점으로 돌아올 때 x좌표가 시작점과 같은 점들의 경우
	// 본래와 다르게 y좌표가 작아지도록 순서를 바꿔줘야 함
	int rev;
	for(rev=N-1; p[rev].x==p[0].x; rev--);
	rev++;
	reverse(p+rev, p+N);
	printf("%d\n", N);
	for(int i=0; i<N; i++)
		printf("%d %d\n", p[i].x, p[i].y);
}