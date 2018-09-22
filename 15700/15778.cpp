#include <cstdio>
#include <cctype>
using namespace std;
const int go[30] = { // general move
	1, 2, 3, 4, 5,
	21, 7, 8, 9, 10,
	26, 12, 13, 14, 15,
	16, 17, 18, 19, 20,
	0, 22, 23, 28, 25,
	15, 27, 23, 29, 20
};
const int startMove[30] = { // if moving is >= than this...
	0, 5, 4, 3, 2,
	4, 5, 4, 3, 2,
	0, 0, 0, 0, 0,
	0, 0, 0, 0, 0,
	0, 3, 2, 0, 0,
	0, 0, 0, 0, 0
};
const int startNext[30] = { // firstly move to this state and so on
	-1, 6, 6, 6, 6,
	24, 11, 11, 11, 11,
	-1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1,
	-1, 24, 24, -1, -1,
	-1, -1, -1, -1, -1
};
const int MAP_SIZE = 32;
char board[MAP_SIZE][MAP_SIZE+1] = {
"..----..----..----..----..----..",
"..    ..    ..    ..    ..    ..",
"| \\                          / |",
"|  \\                        /  |",
"|   \\                      /   |",
"|    ..                  ..    |",
"..   ..                  ..   ..",
"..     \\                /     ..",
"|       \\              /       |",
"|        \\            /        |",
"|         ..        ..         |",
"|         ..        ..         |",
"..          \\      /          ..",
"..           \\    /           ..",
"|             \\  /             |",
"|              ..              |",
"|              ..              |",
"|             /  \\             |",
"..           /    \\           ..",
"..          /      \\          ..",
"|         ..        ..         |",
"|         ..        ..         |",
"|        /            \\        |",
"|       /              \\       |",
"..     /                \\     ..",
"..   ..                  ..   ..",
"|    ..                  ..    |",
"|   /                      \\   |",
"|  /                        \\  |",
"| /                          \\ |",
"..    ..    ..    ..    ..    ..",
"..----..----..----..----..----.."
};
const int mr[30] = {
	-1, 24, 18, 12, 6, 0, 0, 0, 0, 0,
	0, 6, 12, 18, 24, 30, 30, 30, 30, 30,
	30, 5, 10, 15, 20, 25, 5, 10, 20, 25
};
const int mc[30] = {
	-1, 30, 30, 30, 30, 30, 24, 18, 12, 6,
	0, 0, 0, 0, 0, 0, 6, 12, 18, 24,
	30, 25, 20, 15, 10, 5, 5, 10, 20, 25
};



int main(){
	int N, pos[2][4] = {0};
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		char c;
		int cnt = 0;
		scanf(" %c", &c);
		for(int j=0; j<4; j++){
			char stick;
			scanf(" %c", &stick);
			if(stick == 'F') cnt++;
		}
		if(cnt == 0) cnt = 5;

		bool turn = islower(c), isMoving[2][4] = {false,};
		int cn = c - (turn ? 'a' : 'A');
		if(pos[turn][cn] != 0){
			for(int i=0; i<4; i++)
				if(pos[turn][cn] == pos[turn][i]) isMoving[turn][i] = true;
		}
		else isMoving[turn][cn] = true;
		int curr = pos[turn][cn], next = pos[turn][cn];
		if(startMove[curr] > 0 && cnt >= startMove[curr]){
			cnt -= startMove[curr];
			next = startNext[curr];
		}
		for(; cnt>0; cnt--){
			next = go[next];
			if(next == 0) break;
		}
		
		for(int i=0; i<4; i++){
			if(isMoving[turn][i]) pos[turn][i] = next;
			if(next != 0 && pos[!turn][i] == next) pos[!turn][i] = 0;
		}
	}

	for(int i=0; i<2; i++){
		for(int j=0; j<4; j++){
			int p = pos[i][j];
			if(p != 0) board[ mr[p]+(j>=2) ][ mc[p]+(j%2) ] = (i ? 'a' : 'A') + j;
		}
	}
	for(int i=0; i<MAP_SIZE; i++) puts(board[i]);
}