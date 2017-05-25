#include <cstdio>
#include <algorithm>
using namespace std;

inline int cross(int x1, int y1, int x2, int y2){
	return x1*y2 - x2*y1;
}

inline int ccw(int x1, int y1, int x2, int y2, int x3, int y3){
	int temp = cross(x2-x1, y2-y1, x3-x1, y3-y1);
	if(temp == 0) return 0;
	return (temp > 0 ? 1 : -1);
}

inline bool intersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
	if(x1 > x3 || x1 == x3 && y1 > y3) return intersect(x3, y3, x4, y4, x1, y1, x2, y2);
	if(x1 == x2 && x2 == x3 && x3 == x4) return y2 >= y3;
	if((x2-x1)*(y3-y2) == (y2-y1)*(x3-x2) && (x3-x2)*(y4-y3) == (y3-y2)*(x4-x3)) return x2 >= x3;

	int p = ccw(x1, y1, x2, y2, x3, y3);
	int q = ccw(x1, y1, x2, y2, x4, y4);
	if(p && q && p == q) return false;
	int r = ccw(x3, y3, x4, y4, x1, y1);
	int s = ccw(x3, y3, x4, y4, x2, y2);
	if(r && s && r == s) return false;
	return true;
}

struct UnionFind{
	int p[3000];
	UnionFind(){ fill(p, p+3000, -1); }
	int f(int a){
		if(p[a] < 0) return a;
		return p[a] = f(p[a]);
	}
	bool u(int a, int b){
		a = f(a);
		b = f(b);
		if(a == b) return false;
		p[a] += p[b];
		p[b] = a;
		return true;
	}
};



int main(){
	int N, x1[3000], y1[3000], x2[3000], y2[3000];
	UnionFind UF;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d %d %d %d", x1+i, y1+i, x2+i, y2+i);
		if(x1[i] > x2[i] || x1[i] == x2[i] && y1[i] > y2[i]){
			swap(x1[i], x2[i]);
			swap(y1[i], y2[i]);
		}
		for(int j=0; j<i; j++)
			if(intersect(x1[i], y1[i], x2[i], y2[i], x1[j], y1[j], x2[j], y2[j])) UF.u(i, j);
	}
	int cnt = 0, result = -1;
	for(int i=0; i<N; i++){
		if(UF.p[i] < 0){
			cnt++;
			result = max(result, -UF.p[i]);
		}
	}
	printf("%d\n%d\n", cnt, result);
}