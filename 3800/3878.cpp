#include <cstdio>
#include <cmath>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> IP;

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

// line AB, line CD
bool collision(const Point& A, const Point& B, const Point &C, const Point& D){
	if(collision(A, B, C) || collision(A, B, D) || collision(C, D, A) || collision(C, D, B)) return true;
	if(slope(A, B) == slope(C, D)) return false;
	if(sign(ccw(A, B, C)) != sign(ccw(A, B, D)) && sign(ccw(C, D, A)) != sign(ccw(C, D, B))) return true;
	return false;
}



int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N[2], H[2], hull[2][100];
		scanf("%d %d", &N[0], &N[1]);
		Point p[2][100], q[100];
		for(int i=0; i<2; i++){
			for(int j=0; j<N[i]; j++){
				int x, y;
				scanf("%d %d", &x, &y);
				p[i][j] = Point(x, y);
			}
			if(N[i] == 1){
				H[i] = 1;
				hull[i][0] = 0;
				continue;
			}

			sort(p[i], p[i]+N[i]);
			for(int j=1; j<N[i]; j++){
				p[i][j].p = p[i][j].x - p[i][0].x;
				p[i][j].q = p[i][j].y - p[i][0].y;
			}
			sort(p[i]+1, p[i]+N[i]);

			stack<int> S;
			S.push(0);
			S.push(1);
			int next = 2;
			while(next < N[i]){
				while(S.size() >= 2){
					int first, second;
					first = S.top();
					S.pop();
					second = S.top();
					if(ccw(p[i][second], p[i][first], p[i][next]) > 0){
						S.push(first);
						break;
					}
				}
				S.push(next++);
			}

			H[i] = S.size();
			int cnt = 0;
			while(!S.empty()){
				hull[i][cnt++] = S.top();
				S.pop();
			}
		}

		bool result = true;
		// 1 point - 1 point: YES
		if(H[0] == 1 && H[1] == 1);
		// 1 point - n points
		else if(H[0] == 1){
			// do collision test with all lines
			Point& R = p[0][hull[0][0]];
			for(int j=0; j<H[1]; j++){
				int jj = (j+1) % H[1];
				Point& P = p[1][hull[1][j]];
				Point& Q = p[1][hull[1][jj]];
				if(collision(P, Q, R)){
					result = false;
					break;
				}
			}
			// check if the point is in polygon
			if(result){
				bool sign[2] = {0};
				for(int j=0; j<H[1]; j++){
					int jj = (j+1) % H[1];
					Point& P = p[1][hull[1][j]];
					Point& Q = p[1][hull[1][jj]];
					if(ccw(P, Q, R) > 0) sign[1] = true;
					else sign[0] = true;
				}
				if(!(sign[0] && sign[1])){
					result = false;
					break;
				}
			}
		}
		// n point - 1 points
		else if(H[1] == 1){
			// do collision test with all lines
			Point& R = p[1][hull[1][0]];
			for(int i=0; i<H[0]; i++){
				int ii = (i+1) % H[0];
				Point& P = p[0][hull[0][i]];
				Point& Q = p[0][hull[0][ii]];
				if(collision(P, Q, R)){
					result = false;
					break;
				}
			}
			// check if the point is in polygon
			if(result){
				bool sign[2] = {0};
				for(int i=0; i<H[0]; i++){
					int ii = (i+1) % H[0];
					Point& P = p[0][hull[0][i]];
					Point& Q = p[0][hull[0][ii]];
					if(ccw(P, Q, R) > 0) sign[1] = true;
					else sign[0] = true;
				}
				if(!(sign[0] && sign[1])){
					result = false;
					break;
				}
			}
		}
		// m points - n points
		else{
		//	printf("hSize %d %d\n", H[0], H[1]);
			// do collision test for all pairs of each lines
			for(int i=0; i<H[0]; i++){
				int ii = (i+1) % H[0];
				for(int j=0; j<H[1]; j++){
					int jj = (j+1) % H[1];
					Point& P = p[0][hull[0][i]];
					Point& Q = p[0][hull[0][ii]];
					Point& R = p[1][hull[1][j]];
					Point& S = p[1][hull[1][jj]];
				//	bool flag = collision(P, Q, R, S);
				//	printf("%d(%d, %d)%d(%d, %d) %d(%d, %d)%d(%d, %d): %d\n", i, P.x, P.y, ii, Q.x, Q.y, j, R.x, R.y, jj, S.x, S.y, flag);
					if(collision(P, Q, R, S)){
						result = false;
						break;
					}
				}
				if(!result) break;
			}
			// check if one is in another one
			if(result){
				for(int k=0; k<2; k++){
					if(H[k] == 2) continue;
					bool sign[2] = {0};
					for(int i=0; i<H[k]; i++){
						int ii = (i+1) % H[k];
						Point& P = p[k][hull[k][i]];
						Point& Q = p[k][hull[k][ii]];
						Point& R = p[!k][hull[!k][0]];
						if(ccw(P, Q, R) > 0) sign[1] = true;
						else sign[0] = true;
					}
					if(!(sign[0] && sign[1])){
						result = false;
						break;
					}
				}
			}
		}
		puts(result ? "YES" : "NO");
	}
}