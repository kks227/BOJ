#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;
typedef function<pair<int, int>(int, int)> PairFunction;
const bool b[7][4][4] = {
	{1,1,1,1,},
	{1,1,0,0, 1,1,0,0,},
	{1,0,0,0, 1,0,0,0, 1,1,0,0,},
	{0,1,0,0, 0,1,0,0, 1,1,0,0,},
	{1,0,0,0, 1,1,0,0, 0,1,0,0,},
	{0,1,0,0, 1,1,0,0, 1,0,0,0,},
	{1,1,1,0, 0,1,0,0,}
};
PairFunction rot[] = {
	[](int i, int j){ return pair<int, int>(i, j); },
	[](int i, int j){ return pair<int, int>(j, 3-i); },
	[](int i, int j){ return pair<int, int>(3-i, 3-j); },
	[](int i, int j){ return pair<int, int>(3-j, i); }
};

int R, C, map[500][500], result;

void cover(int k, int r, int i, int j){
	int temp = 0;
	for(int ii=0; ii<4; ii++){
		for(int jj=0; jj<4; jj++){
			if(!b[k][ii][jj]) continue;

			int rr, cc;
			tie<int, int>(rr, cc) = rot[r](ii, jj);
			rr += i; cc += j;
			if(rr < 0 || rr >= R || cc < 0 || cc >= C) return;
			temp += map[rr][cc];
		}
	}
	result = max(result, temp);
}

int main(){
	scanf("%d %d", &R, &C);
	for(int i=0; i<R; i++)
		for(int j=0; j<C; j++)
			scanf("%d", &map[i][j]);
	for(int k=0; k<7; k++)
		for(int r=0; r<4; r++)
			for(int i=-3; i<R; i++)
				for(int j=-3; j<C; j++)
					cover(k, r, i, j);
	printf("%d\n", result);
}