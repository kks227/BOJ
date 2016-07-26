#include <cstdio>
using namespace std;

int main(){

	int r[25], c[25];
	int cnt = 0, result = 0, n;
	int row[5] = {0}, col[5] = {0}, dia[2] = {0};
	for(int i=0; i<25; i++){
		scanf("%d", &n);
		n--;
		r[n] = i/5;
		c[n] = i%5;
	}
	for(int i=1; i<=25; i++){
		scanf("%d", &n);
		n--;
		if(result) continue;
		if(++row[r[n]] == 5) cnt++;
		if(++col[c[n]] == 5) cnt++;
		if(r[n]==c[n] && ++dia[0] == 5) cnt++;
		if(r[n]==4-c[n] && ++dia[1] == 5) cnt++;
		if(cnt >= 3) result = i;
	}
	printf("%d\n", result);

	return 0;
}