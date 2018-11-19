#include <cstdio>
#include <queue>
using namespace std;
const int roff[3][8] = {
	-1, -1, 0, 0, 1, 1, 0, 0,
	-2, -2, -1, 1, 2, 2, 1, -1,
	-3, -3, -2, 2, 3, 3, 2, -2
};
const int coff[3][8] = {
	0, 0, 1, 1, 0, 0, -1, -1,
	-1, 1, 2, 2, 1, -1, -2, -2,
	-2, 2, 3, 3, 2, -2, -3, -3
};
const int R = 10;
const int C = 9;

int main(){
	int r1, c1, r2, c2;
	scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
	queue<int> Q;
	bool visited[R][C] = {false,};
	Q.push(r1*10 + c1);
	visited[r1][c1] = true;
	for(int result = 1; !Q.empty(); ++result){
		int qSize = Q.size();
		for(int i = 0; i < qSize; ++i){
			int r = Q.front()/10, c = Q.front()%10;
			Q.pop();
			for(int d = 0; d < 8; ++d){
				int nr = r+roff[2][d], nc = c+coff[2][d];
				if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
				if(r+roff[0][d] == r2 && c+coff[0][d] == c2) continue;
				if(r+roff[1][d] == r2 && c+coff[1][d] == c2) continue;
				if(nr == r2 && nc == c2){
					printf("%d\n", result);
					return 0;
				}
				if(!visited[nr][nc]){
					visited[nr][nc] = true;
					Q.push(nr*10 + nc);
				}
			}
		}
	}
	puts("-1");
}