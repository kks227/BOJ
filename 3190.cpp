#include <cstdio>
#include <list>
#include <utility>
using namespace std;
typedef pair<int, int> IIpair;
typedef pair<int, char> ICpair;
const int roff[4] = {-1, 0, 1, 0};
const int coff[4] = {0, 1, 0, -1};

int main(){
	int N, K, L;
	scanf("%d %d", &N, &K);
	char map[100][100] = {0};
	for(int i=0; i<K; i++){
		int R, C;
		scanf("%d %d", &R, &C);
		map[R-1][C-1] = 2;
	}
	ICpair moving[100];
	scanf("%d", &L);
	for(int i=0; i<L; i++){
		int X;
		char C;
		scanf("%d %c", &X, &C);
		moving[i] = make_pair(X, C);
	}
	list<IIpair> snake;
	snake.push_front(make_pair(0, 0));
	map[0][0] = 1;
	int dir = 1, r = 0, c = 0, m = 0;

	int t = 1;
	while(1){
		int nr = r+roff[dir];
		int nc = c+coff[dir];
		if(nr<0 || nr>=N || nc<0 || nc>=N || map[nr][nc]==1) break;
		if(map[nr][nc] == 0){
			map[snake.back().first][snake.back().second] = 0;
			snake.pop_back();
		}
		map[nr][nc] = 1;
		snake.push_front(make_pair(nr, nc));
		r = nr;
		c = nc;

		if(m < L && moving[m].first == t)
			dir = (dir + (moving[m++].second=='L' ? 3 : 1)) % 4;

		t++;
	}
	printf("%d\n", t);
}