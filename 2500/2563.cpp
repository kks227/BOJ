#include <cstdio>
#include <cstring>
using namespace std;

int main(){

	bool map[100][100] = {0};
	int N, x, y;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d %d", &x, &y);
		for(int i=0; i<10; i++)
			memset(&map[y+i][x], 1, 10);
	}
	int result = 0;
	for(int i=0; i<100; i++)
		for(int j=0; j<100; j++)
			result += map[i][j];
	printf("%d\n", result);
 
    return 0;
}