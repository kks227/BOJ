#include <cstdio>
#include <cstring>
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
	int p = ccw(x1, y1, x2, y2, x3, y3);
	int q = ccw(x1, y1, x2, y2, x4, y4);
	if(p && q && p == q) return false;
	p = ccw(x3, y3, x4, y4, x1, y1);
	q = ccw(x3, y3, x4, y4, x2, y2);
	if(p && q && p == q) return false;
	return true;
}

int main(){
	int x[4], y[4];
	for(int i=0; i<4; i++)
		scanf("%d %d", x+i, y+i);
	printf("%d\n", intersect(x[0], y[0], x[1], y[1], x[2], y[2], x[3], y[3]));
}