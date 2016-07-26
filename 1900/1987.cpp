#include <iostream>
using namespace std;

char** map;
bool alpha[26];
int R, C;
int longest;

void DFS_longest(int r, int c, int present_cnt);

int main(){
	longest = 0;
	cin >> R >> C;
	//초기화 및 동적 할당
	map = new char*[R];
	for(int i=0; i<R; i++){
		map[i] = new char[C];
		for(int j=0; j<C; j++){
			cin >> map[i][j];
		}
	}
	
	DFS_longest(0, 0, 1);
	cout << longest << endl;
	
	return 0;
}

void DFS_longest(int r, int c, int present_cnt){
//	cout << "현재 위치: (" << r << ", " << c << ")" << endl;
	bool LeastOneProgress = false;
	alpha[ map[r][c] ] = true;

	//위
	if(r>0){
		if( alpha[ map[r-1][c] ] == false ){
			DFS_longest(r-1, c, present_cnt+1);
			LeastOneProgress = true;
		}
	}
	//아래
	if(r<R-1){
		if( alpha[ map[r+1][c] ] == false ){
			DFS_longest(r+1, c, present_cnt+1);
			LeastOneProgress = true;
		}
	}
	//왼쪽
	if(c>0){
		if( alpha[ map[r][c-1] ] == false ){
			DFS_longest(r, c-1, present_cnt+1);
			LeastOneProgress = true;
		}
	}
	//오른쪽
	if(c<C-1){
		if( alpha[ map[r][c+1] ] == false ){
			DFS_longest(r, c+1, present_cnt+1);
			LeastOneProgress = true;
		}
	}

	alpha[ map[r][c] ] = false;
	if(LeastOneProgress == false && present_cnt > longest){
		longest = present_cnt;
	//	cout << "현재 최단경로: " << longest << endl;
	}
}