#include <cstdio>
using namespace std;

double P[4];
bool visited[29][29];
const int roff[4] = {0, 0, 1, -1};
const int coff[4] = {1, -1, 0, 0};

double crazyRobot(int r, int c, int limit){
	if(limit == 0) return 1.0;

	visited[r][c] = true;
	double result = 0.0;
	for(int d=0; d<4; d++){
		int nr = r + roff[d];
		int nc = c + coff[d];
		if(visited[nr][nc]) continue;
		result += P[d] * crazyRobot(nr, nc, limit-1);
	}
	visited[r][c] = false;
	return result;
}

int main(){
	int N;
	scanf("%d", &N);
	for(int i=0; i<4; i++){
		int p;
		scanf("%d", &p);
		P[i] = p/100.0;
	}
	printf("%.10lf\n", crazyRobot(14, 14, N));
}