#include <cstdio>
using namespace std;

int N;
bool invalid(int r, int c){
	return r<0 || r>=N || c<0 || c>=N;
}

int main(){
	int map[10][10] = {0}, offset[8][2] = {-1, -1, -1, 0, -1, 1, 0, -1, 0, 1, 1, -1, 1, 0, 1, 1};
	scanf("%d", &N);
	bool mine[10][10], clear[10][10];
	for(int i=0; i<N; i++){
		getchar();
		for(int j=0; j<N; j++){
			if(mine[i][j] = getchar()=='*'){
				for(int k=0; k<8; k++){
					if(invalid(i+offset[k][0], j+offset[k][1])) continue;
					map[i+offset[k][0]][j+offset[k][1]]++;
				}
			}
		}
	}
	for(int i=0; i<N; i++){
		getchar();
		for(int j=0; j<N; j++)
			clear[i][j] = getchar()=='x';
	}
	bool trap = false;
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			if(clear[i][j] && mine[i][j]) trap = true;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++)
			putchar( (trap&&mine[i][j]) ? '*' : (clear[i][j]?map[i][j]+'0':'.') );
		puts("");
	}
}