#include <cstdio>
#include <queue>
using namespace std;

const int roff[12] = {-1, 1, 0, 0, -1, -2, -2, -1, 1, 2, 2, 1};
const int coff[12] = {0, 0, -1, 1, -2, -1, 1, 2, -2, -1, 1, 2};

int main(){
	int K, W, H;
	scanf("%d %d %d", &K, &W, &H);
	bool map[200][200];
	for(int i=0; i<H; i++)
		for(int j=0; j<W; j++)
			scanf("%d", &map[i][j]);

	bool visited[31][200][200] = {0};
	visited[K][0][0] = true;
	queue<int> Q;
	Q.push(K*1000000);
	int result = 0;
	bool success = false;

	while(!Q.empty()){
		int qSize = Q.size();
		for(int i=0; i<qSize; i++){
			int k = Q.front()/1000000;
			int r = Q.front()%1000000/1000;
			int c = Q.front()%1000;
			Q.pop();
			if(r==H-1 && c==W-1){
				success = true;
				break;
			}

			for(int d=0; d<12; d++){
				if(d==4 && k==0) break;

				int nk = k;
				int nr = r + roff[d];
				int nc = c + coff[d];
				if(d >= 4) nk--;
				if(nr<0 || nr>=H || nc<0 || nc>=W) continue;
				if(map[nr][nc]) continue;
				if(visited[nk][nr][nc]) continue;
				visited[nk][nr][nc] = true;
				Q.push(nk*1000000 + nr*1000 + nc);
			}
		}

		if(success) break;
		result++;
	}

	if(success) printf("%d\n", result);
	else puts("-1");
}