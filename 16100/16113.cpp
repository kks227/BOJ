#include <cstdio>
using namespace std;

const char seg[5][10][4] = {
	"###", "#", "###", "###", "#.#", "###", "###", "###", "###", "###",
	"#.#", "#", "..#", "..#", "#.#", "#..", "#..", "..#", "#.#", "#.#",
	"#.#", "#", "###", "###", "###", "###", "###", "..#", "###", "###",
	"#.#", "#", "#..", "..#", "..#", "..#", "#.#", "..#", "#.#", "..#",
	"###", "#", "###", "###", "..#", "###", "###", "..#", "###", "###"
};
const int cols[10] = {3, 1, 3, 3, 3, 3, 3, 3, 3, 3};

int main(){
	int N, C;
	char S[100001];
	scanf("%d %s", &N, S);
	C = N/5;

	for(int pos=0; pos<C; pos++){
		if(S[pos] == '.') continue;
		for(int d=0; d<10; d++){
			bool flag = true;
			for(int r=0; flag && r<5; r++){
				for(int c=0; c<cols[d]; c++)
					if(seg[r][d][c] != S[r*C+pos+c]) flag = false;
				if(pos+cols[d] < C && S[pos+cols[d]] == '#') flag = false;
			}
			if(flag){
				putchar(d+'0');
				pos += cols[d];
				break;
			}
		}
	}
}