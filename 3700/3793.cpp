#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string X, Y;
vector<vector<int>> dp;

int LCS(int x, int y){
	int &ret = dp[x][y];
	if(ret != -1) return ret;
	if(x == X.size() || y == Y.size()) return ret = 0;

	ret = max(LCS(x+1, y), LCS(x, y+1));
	if(X[x] == Y[y]) ret = max(ret, LCS(x+1, y+1) + 1);
	return ret;
}

int main(){
	while(cin >> X >> Y){
		dp = vector<vector<int>>(X.size()+1, vector<int>(Y.size()+1, -1));
		printf("%d\n", LCS(0, 0));
	}
}