#include <cstdio>
#include <cstring>
using namespace std;

int map[9][9], cnt;
bool usedRow[9][10];
bool usedCol[9][10];
bool usedSqr[9][10];

inline int sn(int i, int j){
	return (i/3*3+j/3);
}

bool sudoku(){
	if(cnt==81) return true;

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
			if(tcnt == 0) return false;
			if(tcnt == 1){
				map[i][target] = n;
				usedRow[i][n] = usedCol[target][n] = usedSqr[sn(i,target)][n] = true;
				cnt++;
				if(sudoku()) return true;
				else{
					map[i][target] = 0;
					usedRow[i][n] = usedCol[target][n] = usedSqr[sn(i,target)][n] = false;
					cnt--;
					return false;
				}
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
			if(tcnt == 0) return false;
			if(tcnt == 1){
				map[target][j] = n;
				usedRow[target][n] = usedCol[j][n] = usedSqr[sn(target,j)][n] = true;
				cnt++;
				if(sudoku()) return true;
				else{
					map[target][j] = 0;
					usedRow[target][n] = usedCol[j][n] = usedSqr[sn(target,j)][n] = false;
					cnt--;
					return false;
				}
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
			if(tcnt == 0) return false;
			if(tcnt == 1){
				map[ti][tj] = n;
				usedRow[ti][n] = usedCol[tj][n] = usedSqr[k][n] = true;
				cnt++;
				if(sudoku()) return true;
				else{
					map[ti][tj] = 0;
					usedRow[ti][n] = usedCol[tj][n] = usedSqr[k][n] = false;
					cnt--;
					return false;
				}
			}
		}

	// cell scan
	for(int i=0; i<9; i++)
		for(int j=0; j<9; j++){
			if(map[i][j]) continue;

			int target = -1, tcnt = 0;
			for(int n=1; n<=9; n++)
				if(!usedRow[i][n] && !usedCol[j][n] && !usedSqr[sn(i,j)][n]){
					target = n;
					tcnt++;
				}
			if(tcnt == 0) return false;
			if(tcnt == 1){
				map[i][j] = target;
				usedRow[i][target] = usedCol[j][target] = usedSqr[sn(i,j)][target] = true;
				cnt++;
				if(sudoku()) return true;
				else{
					map[i][j] = 0;
					usedRow[i][target] = usedCol[j][target] = usedSqr[sn(i,j)][target] = false;
					cnt--;
					return false;
				}
			}
		}

	// randomly choose
	for(int i=0; i<9; i++)
		for(int j=0; j<9; j++){
			if(map[i][j]) continue;

			for(int n=1; n<=9; n++)
				if(!usedRow[i][n] && !usedCol[j][n] && !usedSqr[sn(i,j)][n]){
					map[i][j] = n;
					usedRow[i][n] = usedCol[j][n] = usedSqr[sn(i,j)][n] = true;
					cnt++;
					if(sudoku()) return true;
					map[i][j] = 0;
					usedRow[i][n] = usedCol[j][n] = usedSqr[sn(i,j)][n] = false;
					cnt--;
				}
			return false;
		}

	return false;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		memset(usedRow, 0, sizeof(usedRow));
		memset(usedCol, 0, sizeof(usedCol));
		memset(usedSqr, 0, sizeof(usedSqr));
		cnt = 0;
		bool valid = true;
		for(int i=0; i<9; i++)
			for(int j=0; j<9; j++){
				scanf("%1d", &map[i][j]);
				if(map[i][j]){
					cnt++;
					if(usedRow[i][map[i][j]] || usedCol[j][map[i][j]] || usedSqr[sn(i,j)][map[i][j]]) valid = false;
					usedRow[i][map[i][j]] = usedCol[j][map[i][j]] = usedSqr[sn(i,j)][map[i][j]] = true;
				}
			}

		if(valid) valid = sudoku();
		if(!valid) puts("Could not complete this grid.\n");
		else{
			for(int i=0; i<9; i++){
				for(int j=0; j<9; j++)
					printf("%d", map[i][j]);
				puts("");
			}
			puts("");
		}
	}
}