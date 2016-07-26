#include <cstdio>
using namespace std;

bool map[3072][6143];

void setStarMap(int y, int x, int ySize, int xSize){
	if(ySize == 3){
		map[y][x+2] = map[y+1][x+1] = map[y+1][x+3] = map[y+2][x] = map[y+2][x+1] = map[y+2][x+2] = map[y+2][x+3] = map[y+2][x+4] = true;
		return;
	}
	setStarMap(y, x+((xSize-1)/2+1)/2, ySize/2, (xSize-1)/2);
	setStarMap(y+ySize/2, x, ySize/2, (xSize-1)/2);
	setStarMap(y+ySize/2, x+(xSize-1)/2+1, ySize/2, (xSize-1)/2);
}

int main(){

	int N;
	scanf("%d", &N);
	int M = 5;
	for(int i=N; i>3; i/=2)
		M = M*2+1;
	
	setStarMap(0, 0, N, M);
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(map[i][j]) putchar('*');
			else putchar(' ');
		}
		putchar('\n');
	}

	return 0;
}