#include <cstdio>
using namespace std;

bool map[1023][2045] = {0};

void star(int depth, int row, int col){
	if(depth==1){
		map[row][col] = true;
		return;
	}
	int width = (2<<depth)-3;
	int height = (1<<depth)-1;
	if(depth%2){
		for(int i=0; i<width; i++)
			map[row+height-1][col+i] = true;
		for(int i=0; i<height-1; i++)
			map[row+i][col+width/2-i] = map[row+i][col+width/2+i] = true;
		star(depth-1, row+height/2, col+(1<<(depth-1)));
	}
	else{
		for(int i=0; i<width; i++)
			map[row][col+i] = true;
		for(int i=1; i<height; i++)
			map[row+i][col+i] = map[row+i][col+width-i-1] = true;
		star(depth-1, row+1, col+(1<<(depth-1)));
	}
}

int main(){
	int N;
	scanf("%d", &N);
	star(N, 0, 0);
	int width = (2<<N)-3;
	int height = (1<<N)-1;
	for(int i=0; i<height; i++){
		for(int j=0; j<(N%2?width-height+i+1:width-i); j++)
			putchar(map[i][j]?'*':' ');
		puts("");
	}
}