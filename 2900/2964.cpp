#include <cstdio>
#include <cmath>
#include <stack>
#include <algorithm>
using namespace std;
const double PI = 3.1415926;
// 방향 순서: Left, Right, Down, Up

// 솔직히 이 문제는 내가 짤수있는 수준이 아니었습니다. COCI 공식 답 보고 짬

struct Point{
	long long x, y;
	bool erased;
	Point *CW, *CCW, *next[4];

	Point(): Point(0, 0){}
	Point(int x1, int y1): x(x1), y(y1){
		erased = false;
		for(int i=0; i<4; i++) next[i] = '\0';
	}
};

inline int oppod(int d){ return d^1; }

inline int sign(long long n){
	if(n == 0) return 0;
	return (n > 0 ? 1 : -1);
}

int ccw(const Point *A, const Point *B, const Point *C){
	return sign((B->x - A->x)*(C->y - A->y) - (B->y - A->y)*(C->x - A->x));
}

long long add(Point *P){
	long long offset = 0;
	P->CCW->CW = P;
	P->CW->CCW = P;
	offset += P->x * P->CCW->y - P->y * P->CCW->x;
	offset += P->CW->x * P->y - P->CW->y * P->x;
	offset -= P->CW->x * P->CCW->y - P->CW->y * P->CCW->x;
	return offset;
}

long long sub(Point *P){
	long long offset = 0;
	P->CCW->CW = P->CW;
	P->CW->CCW = P->CCW;
	offset -= P->x * P->CCW->y - P->y * P->CCW->x;
	offset -= P->CW->x * P->y - P->CW->y * P->x;
	offset += P->CW->x * P->CCW->y - P->CW->y * P->CCW->x;
	return offset;
}



int main(){
	int N;
	scanf("%d", &N);
	// e[D]: D 방향으로 훑을 때 가장 마지막 위치에 있는 못
	Point *p[300000], *e[4];
	for(int i=0; i<N; i++){
		int x, y;
		scanf("%d %d\n", &x, &y);
		p[i] = new Point(x, y);
	}

	// x좌표, y좌표 순으로 정렬하여 상하좌우 인접한 못 연결
	sort(p, p+N, [](const Point *A, const Point *B){ return A->x < B->x; });
	for(int i=0; i<N; i++){
		if(i > 0) p[i]->next[0] = p[i-1];
		else e[0] = p[i];
		if(i < N-1) p[i]->next[1] = p[i+1];
		else e[1] = p[i];
	}
	sort(p, p+N, [](const Point *A, const Point *B){ return A->y < B->y; });
	for(int i=0; i<N; i++){
		if(i > 0) p[i]->next[2] = p[i-1];
		else e[2] = p[i];
		if(i < N-1) p[i]->next[3] = p[i+1];
		else e[3] = p[i];
	}

	// 못을 뽑는 순서 order 배열을 구함
	Point *order[300000];
	int d[300000];
	for(int i=0; i<N-2; i++){
		char c = getchar();
		if(c == 'L'){ order[i] = e[0]; d[i] = 0; }
		else if(c == 'R'){ order[i] = e[1]; d[i] = 1; }
		else if(c == 'D'){ order[i] = e[2]; d[i] = 2; }
		else{ order[i] = e[3]; d[i] = 3; }

		order[i]->erased = true;
		for(int j=0; j<4; j++)
			while(e[j]->erased) e[j] = e[j]->next[oppod(j)];
	}

	// 못을 뽑은 순서의 역순으로 되짚어가며 못을 추가하며 넓이을 구함
	e[0]->CCW = e[0]->CW = e[1];
	e[1]->CCW = e[1]->CW = e[0];
	stack<long long> result;
	long long area = 0; // 실수오차를 없애기 위해 넓이의 2배를 정수형으로 구함
	for(int i=N-3; i>=0; i--){
		Point *P = order[i];
		int cd = d[i], od = oppod(d[i]);

		// 반시계방향으로 가면서 볼록껍질 만들기
		P->CCW = e[cd];
		while(P->CCW != e[od] && ccw(P, P->CCW, P->CCW->CCW) <= 0){
			if(P->CCW != e[cd]) area += sub(P->CCW);
			P->CCW = P->CCW->CCW;
		}
		// 시계방향으로 가면서 볼록껍질 만들기
		P->CW = e[cd];
		while(P->CW != e[od] && ccw(P, P->CW, P->CW->CW) >= 0){
			if(P->CW != e[cd]) area += sub(P->CW);
			P->CW = P->CW->CW;
		}

		if(P->CW != e[cd] && P->CCW != e[cd]) area += sub(e[cd]);
		area += add(P);
		if(P->x < e[0]->x) e[0] = P;
		if(P->x > e[1]->x) e[1] = P;
		if(P->y < e[2]->y) e[2] = P;
		if(P->y > e[3]->y) e[3] = P;
		result.push(area);
	}

	// 설상가상으로 수가 너무 커서 double은 오차로 틀림.
	// 다행히 답이 항상 .5 혹은 .0이라 망정이지... COCI 6번은 다 막장인듯
	while(!result.empty()){
		printf("%lld.%1lld\n", result.top()/2, result.top()%2*5);
		result.pop();
	}
}