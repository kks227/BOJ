#include <cstdio>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int MAX_N = 300000;
const int MAX_Q = 100000;
const int MAX = MAX_N + MAX_Q;

int main(){
	int N, M, x[MAX_N], y[MAX_N], q[MAX_Q][4];
	set<int> xS, yS;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%d %d", x+i, y+i);
		xS.insert(x[i]);
		yS.insert(y[i]);
	}
	scanf("%d", &M);
	for(int i = 0; i < M; ++i){
		scanf("%d %d %d %d", &q[i][0], &q[i][1], &q[i][2], &q[i][3]);
		xS.insert(q[i][0]); xS.insert(q[i][2]);
		yS.insert(q[i][1]); yS.insert(q[i][3]);
	}

	int X = 0, Y = 0;
	unordered_map<int, int> xH, yH;
	vector<int> xPos[MAX], yPos[MAX];
	for(int x: xS)
		xH[x] = X++;
	for(int y: yS)
		yH[y] = Y++;
	for(int i = 0; i < N; ++i){
		x[i] = xH[x[i]];
		y[i] = yH[y[i]];
		xPos[y[i]].push_back(x[i]);
		yPos[x[i]].push_back(y[i]);
	}
	for(int i = 0; i < M; ++i){
		for(int j = 0; j < 2; ++j){
			q[i][j*2] = xH[q[i][j*2]];
			q[i][j*2+1] = yH[q[i][j*2+1]];
		}
	}
	for(int i = 0; i < MAX; ++i){
		sort(xPos[i].begin(), xPos[i].end());
		sort(yPos[i].begin(), yPos[i].end());
	}

	for(int i = 0; i < M; ++i){
		int result = 0;
		int x1 = q[i][0], y1 = q[i][1], x2 = q[i][2], y2 = q[i][3];
		result += upper_bound(xPos[y1].begin(), xPos[y1].end(), x2) - lower_bound(xPos[y1].begin(), xPos[y1].end(), x1);
		result += upper_bound(xPos[y2].begin(), xPos[y2].end(), x2) - lower_bound(xPos[y2].begin(), xPos[y2].end(), x1);
		if(y2-y1 > 1){
			result += lower_bound(yPos[x1].begin(), yPos[x1].end(), y2) - upper_bound(yPos[x1].begin(), yPos[x1].end(), y1);
			result += lower_bound(yPos[x2].begin(), yPos[x2].end(), y2) - upper_bound(yPos[x2].begin(), yPos[x2].end(), y1);
		}
		printf("%d\n", result);
	}
}