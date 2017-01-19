#include <cstdio>
using namespace std;

inline int f(int w, int p, int t){
	if((p+t)/w % 2) return w - (p+t)%w;
	return (p+t)%w;
}

int main(){
	int w, h, p, q, t;
	scanf("%d %d %d %d %d", &w, &h, &p, &q, &t);
	printf("%d %d\n", f(w, p, t), f(h, q, t));
}