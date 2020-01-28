#include <cstdio>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 10;
const int MOD = 10007;
typedef pair<int, int> P;

int R, C;
char A[MAX][MAX];
map<vector<P>, int> dp[MAX+1][MAX+1];

inline void normalize(vector<P> &v1){
	for(auto &p: v1)
		if(p.first > p.second) swap(p.first, p.second);
	sort(v1.begin(), v1.end());
}

int pipe(int r, int c, vector<P> status){
	normalize(status);
	if(dp[r][c].find(status) != dp[r][c].end()) return dp[r][c][status];
	int &ret = dp[r][c][status] = 0;
	if(status.empty() || status[0].first != -1) return ret = 0;
	if(r == R) return ret = (status.size() == 1 && status[0] == P(-1, C-1) ? 1 : 0);

	bool uFlag = false, lFlag = false;
	int uOppo = -1, lOppo = -1, uIndex = -1, uPairPos = 0, lIndex = -1;
	for(int i = 0; i < status.size(); ++i){
		auto &p = status[i];
		if(p.first == c){
			uOppo = p.second;
			uFlag = true;
			uIndex = i;
		}
		if(p.second == c){
			uOppo = p.first;
			uFlag = true;
			uIndex = i;
			uPairPos = 1;
		}
		if(p.second == C){
			lOppo = p.first;
			lFlag = true;
			lIndex = i;
		}
	}
	if(c == C){
		if(lFlag) return ret = 0;
		return ret = pipe(r+1, 0, status);
	}
	if(A[r][c] == '#'){
		if(uFlag || lFlag) return ret = 0;
		return ret = pipe(r, c+1, status);
	}

	if(!uFlag){
		if(!lFlag){
			ret += pipe(r, c+1, status);
			vector<P> v1(status);
			v1.push_back(P(c, C));
			ret += pipe(r, c+1, v1);
		}
		else{
			ret += pipe(r, c+1, status);
			vector<P> v1(status);
			v1[lIndex].second = c;
			ret += pipe(r, c+1, v1);
		}
	}
	else{
		if(!lFlag){
			ret += pipe(r, c+1, status);
			vector<P> v1(status);
			(uPairPos ? v1[uIndex].second : v1[uIndex].first) = C;
			ret += pipe(r, c+1, v1);
		}
		else{
			if(uIndex != lIndex){
				vector<P> v1(status);
				int i = uIndex, j = lIndex;
				if(i > j) swap(i, j);
				v1.erase(v1.begin() + j);
				v1.erase(v1.begin() + i);
				v1.push_back(P(uOppo, lOppo));
				ret += pipe(r, c+1, v1);
			}
		}
	}

	return ret %= MOD;
}

int main(){
	scanf("%d %d", &R, &C);
	for(int i = 0; i < R; ++i){
		getchar();
		for(int j = 0; j < C; ++j)
			A[i][j] = getchar();
	}
	printf("%d\n", pipe(0, 0, vector<P>(1, P(-1, 0)) ));
}