#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int MAX_N = 20;
const int MAX = 15;
const int INF = 1e9;

int N, M, x[MAX_N], y[MAX_N], pn[MAX_N], dp[MAX_N][1<<MAX];

int gogo(int pos, int catched){
	int &ret = dp[pos][catched];
	if(ret != -1) return ret;
	if(catched == (1<<M)-1) return ret = abs(x[pos]) + abs(y[pos]);

	ret = INF;
	for(int i = 0; i < N; ++i){
		if(i == pos) continue;
		ret = min(gogo(i, catched | 1<<pn[i]) + abs(x[i]-x[pos]) + abs(y[i]-y[pos]), ret);
	}
	return ret;
}

int main(){
	cin >> N;
	unordered_map<string, int> H;
	for(int i = 0; i < N; ++i){
		string name;
		cin >> x[i] >> y[i] >> name;
		if(H.find(name) != H.end()) pn[i] = H[name];
		else pn[i] = H[name] = M++;
	}
	memset(dp, -1, sizeof(dp));
	int result = INF;
	for(int i = 0; i < N; ++i)
		result = min(gogo(i, 1<<pn[i]) + abs(x[i]) + abs(y[i]), result);
	cout << result << '\n';
}