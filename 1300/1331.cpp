#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	bool visited[6][6] = {0}, result = true;
	int sr, sc, pr, pc;
	for(int i=0; i<36; i++){
		char str[3];
		scanf("%s", str);
		int r, c;
		r = str[0] - 'A';
		c = str[1] - '1';
		if(visited[r][c]) result = false;
		visited[r][c] = true;
		if(i == 0){
			sr = r;
			sc = c;
		}
		else if(abs(pr-r)==1 && abs(pc-c)==2 || abs(pr-r)==2 && abs(pc-c)==1);
		else result = false;
		pr = r;
		pc = c;
	}
	if(abs(pr-sr)==1 && abs(pc-sc)==2 || abs(pr-sr)==2 && abs(pc-sc)==1);
	else result = false;
	puts(result ? "Valid" : "Invalid");
}