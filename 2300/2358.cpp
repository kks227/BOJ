#include <cstdio>
#include <map>
using namespace std;

int main(){

	int N, X, Y, result = 0;
	scanf("%d", &N);
	map<int, int> x, y;
	for(int i=0; i<N; i++){
		scanf("%d %d", &X, &Y);
		if(++x[X] == 2) result++;
		if(++y[Y] == 2) result++;
	}
	printf("%d\n", result);

	return 0;
}