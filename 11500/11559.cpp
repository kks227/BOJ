#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

inline bool invalid(int r, int c){
	return r<0 || c<0 || r>=12 || c>=6;
}

int main(){
	char map[12][6];
	bool visited[12][6];
	for(int i=0; i<12; i++){
		for(int j=0; j<6; j++)
			map[i][j] = getchar();
		getchar();
	}

	int xoff[4] = {-1, 1, 0, 0};
	int yoff[4] = {0, 0, -1, 1};

	int result = 0;
	while(1){
		bool chain = false;
		vector<int> Q;
		for(int i=0; i<12; i++)
			for(int j=0; j<6; j++)
				if(map[i][j] != '.'){
					Q.push_back(i*6+j);
					memset(visited, 0, sizeof(visited));
					for(int k=0; k<Q.size(); k++){
						int r = Q[k]/6;
						int c = Q[k]%6;
						if(visited[r][c]) continue;
						visited[r][c] = true;
						for(int d=0; d<4; d++){
							int rn = r+yoff[d];
							int cn = c+xoff[d];
							if(invalid(rn, cn)) continue;
							if(visited[rn][cn]) continue;
							if(map[rn][cn] != map[r][c]) continue;
							Q.push_back(rn*6+cn);
						}
					}
					if(Q.size() >= 4){
						for(int i=0; i<Q.size(); i++){
							map[Q[i]/6][Q[i]%6] = '.';
						}
						chain = true;
					}
					Q.clear();
				}

		if(!chain) break;
		result++;

		char newMap[12][6];
		memset(newMap, '.', sizeof(newMap));
		for(int c=0; c<6; c++){
			int r1 = 11;
			for(int r=11; r>=0; r--)
				if(map[r][c] != '.'){
					newMap[r1--][c] = map[r][c];
				}
		}
		memcpy(map, newMap, sizeof(map));
	}
	printf("%d\n", result);
}