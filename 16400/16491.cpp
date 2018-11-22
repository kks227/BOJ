#include <cstdio>
#include <cmath>
#include <numeric>
#include <algorithm>
using namespace std;

inline int sign(int x){
	if(x == 0) return 0;
	return (x > 0 ? 1 : -1);
}

inline int cross(int x1, int y1, int x2, int y2){
	return x1*y2 - x2*y1;
}

inline int ccw(int x1, int y1, int x2, int y2, int x3, int y3){
	return sign(cross(x1-x2, y1-y2, x1-x3, y1-y3));
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

int main(){
	int N, x[2][10], y[2][10], p[10], result[10];
	scanf("%d", &N);
	iota(p, p+N, 0);
	for(int i = 0; i < 2; ++i)
		for(int j = 0; j < N; ++j)
			scanf("%d %d", &x[i][j], &y[i][j]);

	do{
		bool flag = true;
		for(int i = 0; i < N-1; ++i){
			for(int j = i+1; j < N; ++j){
				int x1 = x[0][i], y1 = y[0][i], x2 = x[1][p[i]], y2 = y[1][p[i]];
				int x3 = x[0][j], y3 = y[0][j], x4 = x[1][p[j]], y4 = y[1][p[j]];	
				if(x1 > x2 || x1 == x2 && y1 > y2){
					swap(x1, x2);
					swap(y1, y2);
				}
				if(x3 > x4 || x3 == x4 && y3 > y4){
					swap(x3, x4);
					swap(y3, y4);
				}
				if(intersect(x1, y1, x2, y2, x3, y3, x4, y4)){
					flag = false;
					break;
				}
			}
			if(!flag) break;
		}
		if(flag){
			for(int i = 0; i < N; ++i)
				printf("%d\n", p[i]+1);
			return 0;
		}
	}while(next_permutation(p, p+N));
}