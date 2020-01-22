#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int MAX = 9;
const int INF = 1e9;

int R, C, A[MAX][MAX];
map<vector<int>, int> dp[MAX+1][MAX];

inline void normalize(vector<int> &v1){
	vector<int> v2(v1);
	int cnt = 1, H[MAX+1] = {0,};
	bool used[MAX+1] = {true,};
	for(int i = 0; i < v1.size(); ++i){
		if(!used[v1[i]]){
			H[v1[i]] = cnt++;
			used[v1[i]] = true;
		}
	}
	for(int i = 0; i < v1.size(); ++i)
		v1[i] = H[v2[i]];
}

int minCost(int r, int c, vector<int> status){
	if(c == C) return minCost(r+1, 0, status);
	normalize(status);
	if(dp[r][c].find(status) != dp[r][c].end()) return dp[r][c][status];
	if(r == R){
		for(int i = 0; i < C; ++i)
			if(status[i] > 1) return dp[r][c][status] = INF;
		return dp[r][c][status] = 0;
	}

	int ret = INF;
	// do not choose this cell
	if(status[c] != 0){
		bool flag1 = false, flag2 = true;
		for(int i = 0; i < C; ++i){
			if(status[i] > 1) flag2 = false;
			if(i != c && status[i] == status[c]) flag1 = true;
		}
		if(flag1){
			vector<int> v1(status);
			v1[c] = 0;
			ret = min(minCost(r, c+1, v1), ret);
		}
		if(flag2){
			ret = min(0, ret);
		}
	}
	else{
		ret = min(minCost(r, c+1, status), ret);
	}
	// choose this cell
	{
		vector<int> v1(status);
		if(c == 0){
			if(status[0] == 0) v1[0] = 9;
		}
		else{
			if(status[c] == 0 && status[c-1] == 0) v1[c] = 9;
			else if(status[c] == 0 && status[c-1] != 0) v1[c] = v1[c-1];
			else if(status[c] != 0 && status[c-1] == 0);
			else{
				for(int i = 0; i < C; ++i)
					if(status[i] == status[c] || status[i] == status[c-1]) v1[i] = status[c];
			}
		}
		ret = min(minCost(r, c+1, v1) + A[r][c], ret);
	}

	return dp[r][c][status] = ret;
}

int main(){
	scanf("%d %d", &R, &C);
	for(int i = 0; i < R; ++i)
		for(int j = 0; j < C; ++j)
			scanf("%d", &A[i][j]);
	printf("%d\n", min(minCost(0, 0, vector<int>(C, 0)), 0));
}