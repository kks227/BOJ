#include <cstdio>
#include <cmath>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> IP;
const int MAX = 1002;

struct Point{
	int x, y, p, q;
	Point(): Point(0, 0, 1, 0){}
	Point(int x1, int y1): Point(x1, y1, 1, 0){}
	Point(int x1, int y1, int p1, int q1): x(x1), y(y1), p(p1), q(q1){}
	bool operator <(const Point& O)const{
		if(1LL*q*O.p != 1LL*p*O.q) return 1LL*q*O.p < 1LL*p*O.q;
		if(x != O.x) return x < O.x;
		return y < O.y;
	}
	bool compare(const Point& O)const{
		return x == O.x && y == O.y;
	}
};

double distance(const Point& A, const Point& B){
	return sqrt(pow(A.x-B.x, 2.0) + pow(A.y-B.y, 2.0));
}

long long ccw(const Point& A, const Point& B, const Point& C){
	return 1LL*(B.x-A.x)*(C.y-A.y) - 1LL*(B.y-A.y)*(C.x-A.x);
}

int sign(long long n){
	if(n == 0) return 0;
	return (n < 0 ? -1 : 1);
}

int gcd(int a, int b){
	while(b){
		int c = a % b;
		a = b;
		b = c;
	}
	return a;
}

IP slope(const Point& A, const Point& B){
	IP result(A.x-B.x, A.y-B.y);
	int g = gcd(abs(result.first), abs(result.second));
	result.first /= g;
	result.second /= g;
	if(result.first < 0) return IP(-result.first, -result.second);
	return result;
}

// line AB, point C
bool collision(const Point& A, const Point& B, const Point &C){
	if(A.x == B.x){
		if(A.x != C.x) return false;
		if(A.y < B.y) return A.y <= C.y && C.y <= B.y;
		return B.y <= C.y && C.y <= A.y;
	}
	if(A.y == B.y){
		if(A.y != C.y) return false;
		if(A.x < B.x) return A.x <= C.x && C.x <= B.x;
		return B.x <= C.x && C.x <= A.x;
	}
	if(slope(A, C) != slope(C, B)) return false;
	if(A.x < B.x && !(A.x <= C.x && C.x <= B.x)) return false;
	if(B.x < A.x && !(B.x <= C.x && C.x <= A.x)) return false;
	if(A.y < B.y && !(A.y <= C.y && C.y <= B.y)) return false;
	if(B.y < A.y && !(B.y <= C.y && C.y <= A.y)) return false;
	return true;
}

// line AB, line CD (if the var 'allow' is true, it allows border-intersection)
bool collision(const Point& A, const Point& B, const Point &C, const Point& D, bool allow=false){
	if(collision(A, B, C) || collision(A, B, D) || collision(C, D, A) || collision(C, D, B)) return !allow;
	if(slope(A, B) == slope(C, D)) return false;
	if(sign(ccw(A, B, C)) != sign(ccw(A, B, D)) && sign(ccw(C, D, A)) != sign(ccw(C, D, B))) return true;
	return false;
}

// point A, N-convex polygon B
bool inside(const Point& A, Point *B, int N){
	if(N <= 2) return false;
	for(int i=0; i<N; i++)
		if(collision(B[i], B[(i+1)%N], A)) return false;

	bool flag[2] = {0};
	for(int i=0; i<N; i++){
		if(ccw(B[i], B[(i+1)%N], A) > 0) flag[1] = true;
		else flag[0] = true;
	}
	return !(flag[0] && flag[1]);
}



int main(){
//	freopen("G.in", "r", stdin);
//	freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
	//	printf("TC %d --- ", t+1);
		Point L, E;
		int N;
		scanf("%d %d %d %d %d", &L.x, &L.y, &E.x, &E.y, &N);
		Point p[MAX];
		for(int i=0; i<N; i++){
			int x, y;
			scanf("%d %d", &x, &y);
			p[i] = Point(x, y);
		}
		if(N == 1){
			printf("%.3lf\n", distance(L, E));
			continue;
		}

		sort(p, p+N);
		for(int i=1; i<N; i++){
			p[i].p = p[i].x - p[0].x;
			p[i].q = p[i].y - p[0].y;
		}
		sort(p+1, p+N);

		Point h[MAX];
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
		bool hull[MAX] = {0};
		while(!S.empty()){
			hull[S.top()] = true;
			S.pop();
		}
		int H = 0;
		for(int i=0; i<N; i++)
			if(hull[i]) h[H++] = Point(p[i].x, p[i].y);

	//	printf("hSize: %d ", H);
		if(inside(L, h, H) || inside(E, h, H)) puts("IMPOSSIBLE");
		else{
			bool straight = true;
			for(int i=0; i<H; i++){
				if(collision(h[i], h[(i+1)%H], L, E, true)){
					straight = false;
					break;
				}
			}
			if(straight){
				printf("%.3lf\n", distance(L, E));
				continue;
			}

			h[H++] = L;
			h[H++] = E;
			sort(h, h+H);
			for(int i=1; i<H; i++){
				h[i].p = h[i].x - h[0].x;
				h[i].q = h[i].y - h[0].y;
			}
			sort(h+1, h+H);

		//	printf("? ");
		//	stack<int> S;
			S.push(0);
			S.push(1);
			int next = 2;
			while(next < H){
				while(S.size() >= 2){
					int first, second;
					first = S.top();
					S.pop();
					second = S.top();
					if(ccw(h[second], h[first], h[next]) > 0){
						S.push(first);
						break;
					}
				}
				S.push(next++);
			}
			fill(hull, hull+MAX, false);
		//	bool hull[MAX] = {0};
			while(!S.empty()){
				hull[S.top()] = true;
				S.pop();
			}
			vector<Point> F;
			for(int i=0; i<H; i++)
				if(hull[i]) F.push_back(Point(h[i].x, h[i].y));
			H = F.size();

		//	printf("! ");
			int LN = -1, EN = -1;
			for(int i=0; i<H; i++){
				if(F[i].compare(L)) LN = i;
				if(F[i].compare(E)) EN = i;
			}
			if(LN == -1){
				for(int i=0; i<H; i++){
					if(collision(F[i], F[(i+1)%H], L)){
						F.insert(F.begin()+i+1, L);
						LN = i+1;
						H++;
						break;
					}
				}
			//	printf("LN ");
			}
			if(EN == -1){
				for(int i=0; i<H; i++){
					if(collision(F[i], F[(i+1)%H], E)){
						F.insert(F.begin()+i+1, E);
						EN = i+1;
						if(EN <= LN) LN++;
						H++;
						break;
					}
				}
			//	printf("EN ");
			}/*
			if(H < 7){
			printf("H %d LN %d EN %d\n", H, LN, EN);
			for(int i=0; i<H; i++)
				printf("(%d %d) ", F[i].x, F[i].y);
			}*/

			double dist[MAX], dSum[MAX+1] = {0};
			for(int i=0; i<H; i++){
				dist[i] = distance(F[i], F[(i+1)%H]);
				dSum[i+1] = dSum[i] + dist[i];
			}
			if(LN > EN) swap(LN, EN);
			double result = min(dSum[EN]-dSum[LN], dSum[LN]+dSum[H]-dSum[EN]);
			printf("%.3lf\n", result);
		}
	}
//	fclose(stdin);
//	fclose(stdout);
}