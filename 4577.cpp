#include <cstdio>
#include <cstring>
using namespace std;

int main(){

	int R, C, X, Y, dir, cnt=1, boxCnt, tempCnt;
	char map[15][16] = {0}, input;
	int move[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1}; //UDLR
	bool result, onDest, nextDest, nextDest2;
	while(1){
		scanf("%d %d", &R, &C);
		if(R == 0) break;
		
		memset(map, 0, 15*16);
		boxCnt = 0;
		for(int i=0; i<R; i++){
			getchar();
			for(int j=0; j<C; j++){
				map[i][j] = getchar();
				if(map[i][j] == 'w' || map[i][j] == 'W'){
					X = j;
					Y = i;
					onDest = (map[i][j] == 'W');
				}
				else if(map[i][j] == 'b' || map[i][j] == 'B') boxCnt++;
			}
		}

		getchar();
		result = false;
		while(1){
			input = getchar();
			if(input == '\n') break;
			if(result) continue;
			switch(input){
			case 'U': dir = 0; break;
			case 'D': dir = 1; break;
			case 'L': dir = 2; break;
			default: dir = 3;
			}

			switch(map[ Y+move[dir][0] ][ X+move[dir][1] ]){
			case '.':
			case '+':
				nextDest = (map[ Y+move[dir][0] ][ X+move[dir][1] ] == '+');
				map[Y][X] = onDest?'+':'.';
				onDest = nextDest;
				Y += move[dir][0];
				X += move[dir][1];
				map[Y][X] = onDest?'W':'w';
				break;
			case 'b':
			case 'B':
				nextDest = (map[ Y+move[dir][0] ][ X+move[dir][1] ] == 'B');
				if(map[ Y+move[dir][0]*2 ][ X+move[dir][1]*2 ] != '.'
					&& map[ Y+move[dir][0]*2 ][ X+move[dir][1]*2 ] != '+') break;
				nextDest2 = (map[ Y+move[dir][0]*2 ][ X+move[dir][1]*2 ] == '+');
				map[Y][X] = onDest?'+':'.';
				Y += move[dir][0];
				X += move[dir][1];
				onDest = nextDest;
				map[Y][X] = onDest?'W':'w';
				map[ Y+move[dir][0] ][ X+move[dir][1] ] = nextDest2?'B':'b';
				break;
			}

			if(!result){
				tempCnt = 0;
				for(int i = 0; i < R; i++)
					for(int j = 0; j < C; j++)
						if(map[i][j] == 'B') tempCnt++;
				if(tempCnt == boxCnt) result = true;
			}
		}

		printf("Game %d: %scomplete\n", cnt++, result?"":"in");
		for(int i=0; i<R; i++)
			printf("%s\n", map+i);
	}

	return 0;
}