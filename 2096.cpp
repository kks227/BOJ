#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){

	int colMax[3] = {0}, colMin[3] = {0}, tempMax[3] = {0}, tempMin[3] = {0};
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		for(int j=0; j<3; j++){
			scanf("%d", tempMax+j);
			tempMin[j] = tempMax[j];
			tempMax[j] += max( colMax[1], (j==1)?max(colMax[0], colMax[2]):colMax[j] );
			tempMin[j] += min( colMin[1], (j==1)?min(colMin[0], colMin[2]):colMin[j] );
		}
		memcpy(colMax, tempMax, sizeof(int)*3);
		memcpy(colMin, tempMin, sizeof(int)*3);
	}
	sort(colMax, colMax+3);
	sort(colMin, colMin+3);
	printf("%d %d\n", colMax[2], colMin[0]);

	return 0;
}