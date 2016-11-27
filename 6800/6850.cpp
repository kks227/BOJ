#include <cstdio>
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
	int N;
	scanf("%d", &N);
	Point p[10000];
	for(int i=0; i<N; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		p[i] = Point(x, y);
	}
	if(N <= 2){
		puts("0");
		return 0;
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
	vector<int> H;
	while(!S.empty()){
		H.push_back(S.top());
		S.pop();
	}
	int M = H.size();

	long long sum = 0;
	for(int i=0; i<M; i++)
		sum += 1LL*(p[H[i]].x+p[H[(i+1)%M]].x)*(p[H[i]].y-p[H[(i+1)%M]].y);
	printf("%llu\n", abs(sum)/100);
}