#include <cstdio>
#include <cmath>
using namespace std;

int digits(int n){
	int result = 0;
	do{
		result++;
		n /= 10;
	}while(n>0);
	return result;
}

int main(){

	int r1, c1, r2, c2, rows, cols, loops;
	int result[50][5];
	int maxDigit = 0;
	int offset[4][2] = {0, 1, -1, 0, 0, -1, 1, 0};
	scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
	rows = r2 - r1 + 1;
	cols = c2 - c1 + 1;
	loops = abs(r1);
	if(loops < abs(r2)) loops = abs(r2);
	if(loops < abs(c1)) loops = abs(c1);
	if(loops < abs(c2)) loops = abs(c2);
	loops = loops*2 + 1;
	loops *= loops;

	int dir = 0, r = 0, c = 0, cnt = 0, limit = 1;
	for(int i=1; i<=loops; i++){
		if(r1 <= r && r <= r2 && c1 <= c && c <= c2){
			result[r-r1][c-c1] = i;
			if(maxDigit < digits(i)) maxDigit = digits(i);
		}
		cnt++;
		r += offset[dir][0];
		c += offset[dir][1];
		if(cnt == limit){
			dir++;
			dir %= 4;
			if(dir%2 == 0) limit++;
			cnt = 0;
		}
	}

	int td;
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			td = digits(result[i][j]);
			for(int k=0; k<maxDigit-td; k++)
				putchar(' ');
			printf("%d", result[i][j]);
			putchar(j==cols-1?'\n':' ');
		}
	}

    return 0;
}