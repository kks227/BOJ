#include <cstdio>
using namespace std;

int offset[4][2] = {-1, -1, -1, 1, 1, 1, 1, -1};

bool invalid(int r, int c){
	return r<0 || r>7 || c<0 || c>7;
}

int main(){
	char map[8][8];
	int cnt = 0;
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			map[i][j] = getchar();
			if(map[i][j]=='*') cnt++;
		}
		getchar();
	}
	if(cnt != 8){
		puts("invalid");
		return 0;
	}
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			if(map[i][j] == '.') continue;
			for(int k=0; k<8; k++){
				if(k!=i && map[k][j]=='*'){
					puts("invalid");
					return 0;
				}
				if(k!=j && map[i][k]=='*'){
					puts("invalid");
					return 0;
				}
			}
			for(int k=0; k<4; k++){
				int r = i+offset[k][0];
				int c = j+offset[k][1];
				while(!invalid(r, c)){
					if(map[r][c]=='*'){
						puts("invalid");
						return 0;
					}
					r += offset[k][0];
					c += offset[k][1];
				}
			}
		}
	}
	puts("valid");
}