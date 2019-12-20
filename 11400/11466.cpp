#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int h, w;
	scanf("%d %d", &h, &w);
	printf("%.4lf\n", max(max(min(w*1.0, h/3.0), min(h*1.0, w/3.0)), min(h/2.0, w/2.0)));
}