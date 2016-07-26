#include <cstdio>
using namespace std;

int main(){
	int p, map[3][3] = {0};
	scanf("%d", &p);
	bool end = false;
	for(int i=0; i<9; i++){
		int r, c;
		scanf("%d %d", &r, &c);
		if(end) continue;
		r--; c--;
		map[r][c] = p;

		bool win = true;
		for(int i=0; i<3; i++)
			if(map[i][c] != map[r][c]){
				win = false;
				break;
			}
		if(win) end = true;

		win = true;
		for(int j=0; j<3; j++)
			if(map[r][j] != map[r][c]){
				win = false;
				break;
			}
		if(win) end = true;

		win = true;
		for(int k=0; k<3; k++)
			if(map[k][k] != map[r][c]){
				win = false;
				break;
			}
		if(win) end = true;

		win = true;
		for(int k=0; k<3; k++)
			if(map[k][2-k] != map[r][c]){
				win = false;
				break;
			}
		if(win) end = true;

		if(!end) p = !(p-1) + 1;
	}
	if(!end) puts("0");
	else printf("%d\n", p);
}