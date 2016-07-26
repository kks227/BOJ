#include <cstdio>
using namespace std;

bool map[6561][6561];

void setStarMap(int y, int x, int size){
	if(size == 1){
		map[y][x] = true;
		return;
	}
	setStarMap(y, x, size/3);
	setStarMap(y, x+size/3, size/3);
	setStarMap(y, x+size*2/3, size/3);
	setStarMap(y+size/3, x, size/3);
	setStarMap(y+size/3, x+size*2/3, size/3);
	setStarMap(y+size*2/3, x, size/3);
	setStarMap(y+size*2/3, x+size/3, size/3);
	setStarMap(y+size*2/3, x+size*2/3, size/3);
}

int main(){

	int N;
	scanf("%d", &N);
	setStarMap(0, 0, N);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(map[i][j]) putchar('*');
			else putchar(' ');
		}
		putchar('\n');
	}

	return 0;
}