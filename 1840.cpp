#include <cstdio>
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
				bool result = sudoku();
				map[i][target] = 0;
				usedRow[i][n] = usedCol[target][n] = usedSqr[sn(i,target)][n] = false;
				cnt--;
				return result;
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
				bool result = sudoku();
				map[target][j] = 0;
				usedRow[target][n] = usedCol[j][n] = usedSqr[sn(target,j)][n] = false;
				cnt--;
				return result;
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
				bool result = sudoku();
				map[ti][tj] = 0;
				usedRow[ti][n] = usedCol[tj][n] = usedSqr[k][n] = false;
				cnt--;
				return result;
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
				bool result = sudoku();
				map[i][j] = 0;
				usedRow[i][target] = usedCol[j][target] = usedSqr[sn(i,j)][target] = false;
				cnt--;
				return result;
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
					bool result = sudoku();
					map[i][j] = 0;
					usedRow[i][n] = usedCol[j][n] = usedSqr[sn(i,j)][n] = false;
					cnt--;
					if(result) return true;
				}
			return false;
		}

	return false;
}

int main(){
	int result = -1;
	for(int i=1; i<=81; i++){
		int r, c, n;
		scanf("%d %d %d", &r, &c, &n);
		if(result != -1) continue;
		r--;
		c--;
		if(usedRow[r][n] || usedCol[c][n] || usedSqr[sn(r,c)][n]){
			result = i;
			continue;
		}
		cnt++;
		map[r][c] = n;
		usedRow[r][n] = usedCol[c][n] = usedSqr[sn(r,c)][n] = true;
		if(!sudoku()) result = i;
	}
	printf("%d\n", result);
}