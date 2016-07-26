#include <cstdio>
#include <queue>
using namespace std;

const int roff[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
const int coff[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int I;
		scanf("%d", &I);
		int sr, sc, er, ec;
		scanf("%d %d %d %d", &sr, &sc, &er, &ec);

		queue<int> Q;
		Q.push(sr*I+sc);
		bool visited[300][300] = {0};
		visited[sr][sc] = true;
		int result = 0;
		while(1){
			int qSize = Q.size();
			bool found = false;
			for(int i=0; i<qSize; i++){
				int cr = Q.front()/I;
				int cc = Q.front()%I;
				Q.pop();
				if(cr==er && cc==ec){
					printf("%d\n", result);
					found = true;
					break;
				}
				for(int d=0; d<8; d++){
					int nr = cr + roff[d];
					int nc = cc + coff[d];
					if(nr<0 || nr>=I || nc<0 || nc>=I) continue;
					if(visited[nr][nc]) continue;
					visited[nr][nc] = true;
					Q.push(nr*I+nc);
				}
			}
			if(found) break;
			result++;
		}
	}
}