#include <cstdio>
#include <cctype>
#include <queue>
using namespace std;

struct qInstance{
	int key, r, c;
	qInstance():qInstance(0, 0, 0){}
	qInstance(int key1, int r1, int c1):key(key1), r(r1), c(c1){}
};

const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int main(){
	int N, M;
	char map[50][50];
	int sr, sc;
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		getchar();
		for(int j=0; j<M; j++){
			map[i][j] = getchar();
			if(map[i][j] == '0'){
				sr = i;
				sc = j;
			}
		}
	}

	bool visited[128][50][50] = {0};
	visited[0][sr][sc] = true;
	queue<qInstance> Q;
	Q.push(qInstance(0, sr, sc));
	int result = 0;
	bool success = false;

	while(!Q.empty()){
		int qSize = Q.size();

		for(int i=0; i<qSize; i++){
			int key = Q.front().key;
			int r = Q.front().r;
			int c = Q.front().c;
			Q.pop();
			if(map[r][c] == '1'){
				success = true;
				break;
			}

			for(int d=0; d<4; d++){
				int nkey = key;
				int nr = r + roff[d];
				int nc = c + coff[d];
				if(nr<0 || nr>=N || nc<0 || nc>=M) continue;

				if(map[nr][nc] == '#') continue;
				else if(islower(map[nr][nc])) nkey |= (1 << (map[nr][nc]-'a'));
				else if(isupper(map[nr][nc]))
					if( !(nkey & (1 << (map[nr][nc]-'A'))) ) continue;

				if(visited[nkey][nr][nc]) continue;
				visited[nkey][nr][nc] = true;
				Q.push(qInstance(nkey, nr, nc));
			}
		}

		if(success) break;
		result++;
	}

	if(success) printf("%d\n", result);
	else puts("-1");
}