#include <cstdio>
using namespace std;

int offset[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
int pos[4] = {1, 0, 3, 2}, neg[4] = {3, 2, 1, 0};

int main(){
	for(int t=1; ; t++){
		int W, L;
		scanf("%d %d", &W, &L);
		if(W==0) break;
		int r, c, dir;
		char map[20][20];
		for(int i=0; i<L; i++){
			getchar();
			for(int j=0; j<W; j++)
				if((map[i][j]=getchar())=='*'){
					r = i;
					c = j;
					if(r==L-1) dir = 0;
					else if(c==0) dir = 1;
					else if(r==0) dir = 2;
					else dir = 3;
				}
		}
		while(map[r][c] != 'x'){
			r += offset[dir][0];
			c += offset[dir][1];
			if(map[r][c] == '/') dir = pos[dir];
			else if(map[r][c] == '\\') dir = neg[dir];
		}
		map[r][c] = '&';
		printf("HOUSE %d\n", t);
		for(int i=0; i<L; i++){
			for(int j=0; j<W; j++)
				putchar(map[i][j]);
			puts("");
		}
	}
}