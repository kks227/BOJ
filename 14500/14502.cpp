#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int main(){
	int R, C, map[8][8];
	vector<int> cell, virus;
	scanf("%d %d", &R, &C);
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			scanf("%d", &map[i][j]);
			if(!map[i][j]) cell.push_back(i*10+j);
			else if(map[i][j] == 2) virus.push_back(i*10+j);
		}
	}

	int result = 0;
	for(int i=0; i<cell.size()-2; i++){
		map[cell[i]/10][cell[i]%10] = 1;
		for(int j=i+1; j<cell.size()-1; j++){
			map[cell[j]/10][cell[j]%10] = 1;
			for(int k=j+1; k<cell.size(); k++){
				map[cell[k]/10][cell[k]%10] = 1;

				queue<int> Q;
				bool visited[8][8] = {0};
				for(int p: virus){
					Q.push(p);
					visited[p/10][p%10] = true;
				}
				int cnt = 0;
				while(!Q.empty()){
					int r = Q.front()/10, c = Q.front()%10;
					Q.pop();
					for(int d=0; d<4; d++){
						int nr = r+roff[d], nc = c+coff[d];
						if(nr < 0 || nr >= R || nc < 0 || nc >= C || map[nr][nc] || visited[nr][nc]) continue;
						visited[nr][nc] = true;
						cnt++;
						Q.push(nr*10+nc);
					}
				}
				result = max(result, (int)(cell.size()-cnt-3));

				map[cell[k]/10][cell[k]%10] = 0;
			}
			map[cell[j]/10][cell[j]%10] = 0;
		}
		map[cell[i]/10][cell[i]%10] = 0;
	}
	printf("%d\n", result);
}