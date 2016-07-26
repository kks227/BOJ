#include <cstdio>
using namespace std;

int main(){
	bool map[100][100] = {0};
	for(int k=0; k<4; k++){
		int x1, x2, y1, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for(int i=y1; i<y2; i++)
			for(int j=x1; j<x2; j++)
				map[i][j] = true;
	}
	int result = 0;
	for(int i=0; i<100; i++)
		for(int j=0; j<100; j++)
			result += map[i][j];
	printf("%d\n", result);
}