#include <cstdio>
#include <tuple>
#include <algorithm>
using namespace std;
const int MAX = 300;
typedef tuple<int, int, int> Point;

int main(){
	int N;
	Point p[MAX*3];
	scanf("%d", &N);
	for(int i = 0; i < N*3; ++i){
		int x, y;
		scanf("%d %d", &x, &y);
		p[i] = Point(x, y, i+1);
	}
	sort(p, p+N*3);
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < 3; ++j)
			printf("%d ", get<2>(p[i*3+j]));
		puts("");
	}
}