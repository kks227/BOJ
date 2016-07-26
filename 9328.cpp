#include <cstdio>
#include <cctype>
#include <queue>
using namespace std;

const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int H, W;
		scanf("%d %d\n", &H, &W);
		char map[100][100];
		for(int i=0; i<H; i++){
			for(int j=0; j<W; j++)
				map[i][j] = getchar();
			getchar();
		}
		bool visited[100][100] = {0}, keys[26] = {0};
		while(1){
			char c = getchar();
			if(c == '\n') break;
			if(c != '0') keys[c-'a'] = true;
		}

		queue<int> Q;
		for(int i=0; i<H; i++){
			if(map[i][0] != '*'){
				visited[i][0] = true;
				Q.push(i*100);
			}
			if(map[i][W-1] != '*'){
				visited[i][W-1] = true;
				Q.push(i*100 + W-1);
			}
		}
		for(int j=1; j<W-1; j++){
			if(map[0][j] != '*'){
				visited[0][j] = true;
				Q.push(j);
			}
			if(map[H-1][j] != '*'){
				visited[H-1][j] = true;
				Q.push((H-1)*100 + j);
			}
		}

		int result = 0;
		queue<int> locked[26];
		while(!Q.empty()){
			int r = Q.front()/100;
			int c = Q.front()%100;
			Q.pop();

			visited[r][c] = true;
			if(isupper(map[r][c])){
				int k = map[r][c]-'A';
				if(keys[k]) map[r][c] = '.';
				else{
					locked[k].push(r*100 + c);
					continue;
				}
			}
			else if(islower(map[r][c])){
				int k = map[r][c]-'a';
				if(!keys[k]){
					while(!locked[k].empty()){
						Q.push(locked[k].front());
						locked[k].pop();
					}
					keys[k] = true;
				}
				map[r][c] = '.';
			}
			else if(map[r][c] == '$'){
				result++;
				map[r][c] = '.';
			}

			for(int d=0; d<4; d++){
				int nr = r+roff[d];
				int nc = c+coff[d];
				if(nr<0 || nr>=H || nc<0 || nc>=W || map[nr][nc]=='*' || visited[nr][nc]) continue;
				visited[nr][nc] = true;
				Q.push(nr*100 + nc);
			}
		}
		printf("%d\n", result);
	}
}