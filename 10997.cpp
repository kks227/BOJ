#include <cstdio>
using namespace std;

int width, height, offset[4][2] = {0, -1, 1, 0, 0, 1, -1, 0};
bool map[399][397];

bool invalid(int r, int c){
	return r<0 || r>=height || c<0 || c>=width;
}

int main(){
	int N;
	scanf("%d", &N);
	if(N==1){
		puts("*");
		return 0;
	}
	width = N*4-3;
	height = N*4-1;
	int r = 0, c = width-1, dir = 0, turn = 0;
	while(1){
		map[r][c] = true;
		if(turn>=3 && map[r+offset[dir][0]*2][c+offset[dir][1]*2]) dir = (dir+1)%4;
		else if(invalid(r+offset[dir][0], c+offset[dir][1])) dir = (dir+1)%4;
		if(map[r+offset[dir][0]*2][c+offset[dir][1]*2]) break;
		r += offset[dir][0];
		c += offset[dir][1];
		turn++;
	}
	for(int i=0; i<height; i++){
		if(i==1) putchar('*');
		else for(int j=0; j<width; j++) putchar(map[i][j]?'*':' ');
		puts("");
	}
}