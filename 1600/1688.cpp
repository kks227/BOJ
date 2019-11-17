#include <cstdio>
using namespace std;
const int MAX = 10000;

inline long long cross(int x1, int y1, int x2, int y2){
	return 1LL*x1*y2 - 1LL*x2*y1;
}

inline int ccw(int x1, int y1, int x2, int y2, int x3, int y3){
	long long temp = cross(x2-x1, y2-y1, x3-x1, y3-y1);
	if(temp == 0) return 0;
	return (temp > 0 ? 1 : -1);
}

int main(){
	int N, x[MAX], y[MAX];
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		scanf("%d %d", x+i, y+i);
	for(int k = 0; k < 3; ++k){
		int x0, y0;
		scanf("%d %d", &x0, &y0);
		bool flag = false;
		for(int i = 0; i < N && !flag; ++i)
			if(x0 == x[i] && y0 == y[i] || ccw(x[i], y[i], x[(i+1)%N], y[(i+1)%N], x0, y0) == 0) flag = true;
		if(!flag){
			bool flagP = false, flagM = false;
			for(int i = 0; i < N; ++i){
				int temp = ccw(x[i], y[i], x[(i+1)%N], y[(i+1)%N], x0, y0);
				(temp > 0 ? flagP : flagM) = true;
			}
			flag = !(flagP && flagM);
		}
		printf("%d\n", flag);
	}
}