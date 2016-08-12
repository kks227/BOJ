#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

char map[5][5];
vector<int> pos(7);
bool visited[5][5];
set<vector<int>> result;

void backtrack(int cr, int cc, int s, int k){
	if(map[cr][cc] == 'S') s++;
	if(k-s == 4) return;
	pos[k] = cr*5 + cc;
	if(k == 6){
		if(s > 3){
			vector<int> temp(pos);
			sort(temp.begin(), temp.end());
			result.insert(temp);
		}
		return;
	}

	visited[cr][cc] = true;
	for(int i=0; i<=k; i++){
		for(int d=0; d<4; d++){
			int nr = pos[i]/5 + roff[d];
			int nc = pos[i]%5 + coff[d];
			if(nr<0 || nr>=5 || nc<0 || nc>=5 || visited[nr][nc]) continue;
			backtrack(nr, nc, s, k+1);
		}
	}
	visited[cr][cc] = false;
}

int main(){
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++)
			map[i][j] = getchar();
		getchar();
	}
	for(int i=0; i<5; i++)
		for(int j=0; j<5; j++)
			backtrack(i, j, 0, 0);
	printf("%d\n", result.size());
}
