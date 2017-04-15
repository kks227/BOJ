#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;
const int roff[2] = {1, 0};
const int coff[2] = {0, 1};

int R, C, dp[50][50][50][50];
vector<int> pos[26];
char map[50][50], dp2[50][50][50][50];

bool reachable(int r1, int c1, int r2, int c2){
	char &ret = dp2[r1][c1][r2][c2];
	if(ret != -1) return ret;
	if(r1 == r2 && c1 == c2) return ret = true;
	if(r1 > r2 || c1 > c2) return ret = false;
	if(map[r1][c1] == '#' || map[r2][c2] == '#') return ret = false;

	ret = false;
	if(r1 < R-1) ret |= reachable(r1+1, c1, r2, c2);
	if(c1 < C-1) ret |= reachable(r1, c1+1, r2, c2);
	return ret;
}

int maze(int r1, int c1, int r2, int c2){
	int &ret = dp[r1][c1][r2][c2];
	if(ret != -1) return ret;
	if(r1 == r2 && c1 == c2) return ret = 0;
	if(!reachable(r1, c1, r2, c2)) return ret = 0;

	ret = 0;
	if(r1 < R-1) ret = max(maze(r1+1, c1, r2, c2), ret);
	if(c1 < C-1) ret = max(maze(r1, c1+1, r2, c2), ret);
	if(islower(map[r1][c1])){
		for(int p: pos[map[r1][c1]-'a']){
			int r3 = p/100, c3 = p%100;
			if(reachable(r1, c1, r3, c3) && reachable(r3, c3, r2, c2)){
				for(int i=0; i<2; i++){
					for(int j=0; j<2; j++){
						int nr1 = r1+roff[i], nc1 = c1+coff[i], nr2 = r3-roff[j], nc2 = c3-coff[j];
						if(nr1 < 0 || nr1 >= R || nc1 < 0 || nc1 >= C) continue;
						if(nr2 < 0 || nr2 >= R || nc2 < 0 || nc2 >= C) continue;
						ret = max(ret, maze(nr1, nc1, nr2, nc2) + maze(r3, c3, r2, c2) + 1);
					}
				}
			}
		}
	}
	return ret;
}



int main(){
	while(1){
		scanf("%d %d", &R, &C);
		if(R == 0) break;

		for(int i=0; i<26; i++)
			pos[i].clear();
		for(int i=0; i<R; i++){
			getchar();
			for(int j=0; j<C; j++){
				map[i][j] = getchar();
				if(isupper(map[i][j])) pos[map[i][j]-'A'].push_back(i*100+j);
			}
		}
		memset(dp, -1, sizeof(dp));
		memset(dp2, -1, sizeof(dp2));
		if(!reachable(0, 0, R-1, C-1)) puts("-1");
		else printf("%d\n", maze(0, 0, R-1, C-1));
	}
}