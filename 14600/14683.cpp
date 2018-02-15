#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	int x1, y1, x2, y2, t;
	scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &t);
	puts(t>=abs(x1-x2)+abs(y1-y2) && (t-abs(x1-x2)-abs(y1-y2))%2==0 ? "Y" : "N");
}