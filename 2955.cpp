#include <cstdio>
using namespace std;

int map[9][9], cnt;
bool usedRow[9][10];
bool usedCol[9][10];
bool usedSqr[9][10];
bool error;

inline int sn(int i, int j){
	return (i/3*3+j/3);
}

void sudoku(){
	if(cnt==81) return;

	// row scan
	for(int i=0; i<9; i++)
		for(int n=1; n<=9; n++){
			if(usedRow[i][n]) continue;

			int target = -1, tcnt = 0;
			for(int j=0; j<9; j++)
				if(!map[i][j] && !usedCol[j][n] && !usedSqr[sn(i,j)][n]){
					target = j;
					tcnt++;
				}
			if(tcnt == 0){
				error = true;
				return;
			}
		}

	// col scan
	for(int j=0; j<9; j++)
		for(int n=1; n<=9; n++){
			if(usedCol[j][n]) continue;

			int target = -1, tcnt = 0;
			for(int i=0; i<9; i++)
				if(!map[i][j] && !usedRow[i][n] && !usedSqr[sn(i,j)][n]){
					target = i;
					tcnt++;
				}
			if(tcnt == 0){
				error = true;
				return;
			}
		}

	// small square scan
	for(int k=0; k<9; k++)
		for(int n=1; n<=9; n++){
			if(usedSqr[k][n]) continue;

			int ti = -1, tj = -1, tcnt = 0;
			for(int i=k/3*3; i<k/3*3+3; i++)
				for(int j=k%3*3; j<k%3*3+3; j++)
					if(!map[i][j] && !usedRow[i][n] && !usedCol[j][n]){
						ti = i;
						tj = j;
						tcnt++;
					}
			if(tcnt == 0){
				error = true;
				return;
			}
			if(tcnt == 1){
				map[ti][tj] = n;
				usedRow[ti][n] = usedCol[tj][n] = usedSqr[k][n] = true;
				cnt++;
				sudoku();
				return;
			}
		}
}

int main(){
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			char c = getchar();
			if(c != '.'){
				map[i][j] = c-'0';
				cnt++;
				if(usedRow[i][map[i][j]]) error = true;
				if(usedCol[j][map[i][j]]) error = true;
				if(usedSqr[sn(i,j)][map[i][j]]) error = true;
				usedRow[i][map[i][j]] = usedCol[j][map[i][j]] = usedSqr[sn(i,j)][map[i][j]] = true;
			}
			else map[i][j] = 0;
		}
		getchar();
	}

	if(!error) sudoku();
	if(error){
		puts("ERROR");
		return 0;
	}
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++)
			printf("%c", map[i][j]?map[i][j]+'0':'.');
		puts("");
	}
}