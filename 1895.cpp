#include <cstdio>
#include <algorithm>
using namespace std;

int main(){

	int R, C, T;
	scanf("%d %d", &R, &C);
	int image[40][40];
	for(int i=0; i<R; i++)
		for(int j=0; j<C; j++)
			scanf("%d", &image[i][j]);
	scanf("%d", &T);
	int temp[9], result = 0;
	for(int i=0; i<R-2; i++){
		for(int j=0; j<C-2; j++){
			for(int r=0; r<3; r++)
				for(int c=0; c<3; c++)
					temp[r*3+c] = image[i+r][j+c];
			sort(temp, temp+9);
			if(temp[4] >= T) result++;
		}
	}
	printf("%d\n", result);

	return 0;
}