#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

int main(){

	int N, map[100][100], result, temp;
	int xOffset[13][4] = {
		0, 1, 2, 3,
		0, 0, 0, 0,
		0, 1, 1, 2,
		1, 0, 1, 0,
		0, 1, 2, 2,
		1, 1, 0, 1,
		0, 0, 1, 2,
		0, 1, 0, 0,
		0, 1, 2, 1,
		1, 0, 1, 1,
		1, 0, 1, 2,
		0, 0, 1, 0,
		0, 1, 0, 1
	};
	int yOffset[13][4] = {
		0, 0, 0, 0,
		0, 1, 2, 3,
		0, 0, 1, 1,
		0, 1, 1, 2,
		0, 0, 0, 1,
		0, 1, 2, 2,
		0, 1, 1, 1,
		0, 0, 1, 2,
		0, 0, 0, 1,
		0, 1, 1, 2,
		0, 1, 1, 1,
		0, 1, 1, 2,
		0, 0, 1, 1
	};

	bool flag;
	for(int t=1; ; t++){
		scanf("%d", &N);
		if(N == 0) break;

		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				scanf("%d", &map[i][j]);

		result = INT_MIN;
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				for(int k=0; k<13; k++){
					flag = true;
					temp = 0;
					for(int l=0; l<4; l++){
						if(j+xOffset[k][l] >= N || i+yOffset[k][l] >= N){
							flag = false;
							break;
						}
						temp += map[i+yOffset[k][l]][j+xOffset[k][l]];
					}
					if(!flag) continue;

					result = max(result, temp);
				}
			}
		}
		printf("%d. %d\n", t, result);
	}

	return 0;
}