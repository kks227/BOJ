#include <iostream>
#include <string>
using namespace std;

#define SIZE 8

int main(){

	string king_pos, stone_pos, movement;
	int N;
	int king_row, king_col, stone_row, stone_col, move_row, move_col;
	cin >> king_pos >> stone_pos >> N;
	int map[SIZE][SIZE] = {0};
	king_row = king_pos[1]-'1';
	king_col = king_pos[0]-'A';
	stone_row = stone_pos[1]-'1';
	stone_col = stone_pos[0]-'A';
	map[king_row][king_col] = 1;
	map[stone_row][stone_col] = 2;
	for(int i=0; i<N; i++){
		cin >> movement;
		if(movement == "L"){ move_row = 0; move_col = -1; }
		else if(movement == "R"){ move_row = 0; move_col = 1; }
		else if(movement == "B"){ move_row = -1; move_col = 0; }
		else if(movement == "T"){ move_row = 1; move_col = 0; }
		else if(movement == "LB"){ move_row = -1; move_col = -1; }
		else if(movement == "RB"){ move_row = -1; move_col = 1; }
		else if(movement == "LT"){ move_row = 1; move_col = -1; }
		else{ move_row = 1; move_col = 1; }
		if(king_row+move_row < 0 || king_row+move_row >= SIZE) continue;
		if(king_col+move_col < 0 || king_col+move_col >= SIZE) continue;
		if(map[king_row+move_row][king_col+move_col]){
			if(stone_row+move_row < 0 || stone_row+move_row >= SIZE) continue;
			if(stone_col+move_col < 0 || stone_col+move_col >= SIZE) continue;
			map[king_row][king_col] = 0;
			king_row += move_row;
			king_col += move_col;
			map[king_row][king_col] = 1;
			stone_row += move_row;
			stone_col += move_col;
			map[stone_row][stone_col] = 2;
		}
		else{
			map[king_row][king_col] = 0;
			king_row += move_row;
			king_col += move_col;
			map[king_row][king_col] = 1;
		}
	}
	cout << (char)(king_col+'A') << king_row+1 << endl;
	cout << (char)(stone_col+'A') << stone_row+1 << endl;

	return 0;
}