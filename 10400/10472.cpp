#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool invalid(int r, int c){
	return r<0 || r>2 || c<0 || c>2;
}

int offset[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
bool map[3][3];
int cnt;

bool same(vector<bool> &flag){
	bool temp[3][3] = {0};
	for(int i=0; i<9; i++){
		if(!flag[i]) continue;
		int r = i/3;
		int c = i%3;
		temp[r][c] = !temp[r][c];
		for(int d=0; d<4; d++){
			int nextR = r+offset[d][0];
			int nextC = c+offset[d][1];
			if(invalid(nextR, nextC)) continue;
			temp[nextR][nextC] = !temp[nextR][nextC];
		}
	}
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			if(temp[i][j] != map[i][j]) return false;
	return true;
}

int main(){
	int P;
	scanf("%d\n", &P);
	for(int t=0; t<P; t++){
		cnt = 0;
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++)
				map[i][j] = (getchar()=='*');
			getchar();
		}
		int result = 9;
		for(int i=0; i<512; i++){
			int temp = i, bitCnt = 0;
			vector<bool> flag(9, false);
			for(int j=0; j<9; j++){
				bitCnt += flag[j] = temp%2;
				temp /= 2;
			}
			if(same(flag)) result = min(result, bitCnt);
		}
		printf("%d\n", result);
	}
}