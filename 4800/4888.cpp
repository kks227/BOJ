#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int N, C, x[9], y[9], c[9][9];
map<vector<int>, int> dp;

inline int sign(int n){
	if(n == 0) return 0;
	return (n > 0 ? 1 : -1);
}

inline int cross(int x1, int y1, int x2, int y2){
    return x1*y2 - x2*y1;
}

inline bool intersection(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
	int c1, c2;
	c1 = sign(cross(x2-x1, y2-y1, x3-x1, y3-y1));
	c2 = sign(cross(x2-x1, y2-y1, x4-x1, y4-y1));
	if(c1 == 0 || c2 == 0 || c1 == c2) return false;
	c1 = sign(cross(x4-x3, y4-y3, x1-x3, y1-y3));
	c2 = sign(cross(x4-x3, y4-y3, x2-x3, y2-y3));
	if(c1 == 0 || c2 == 0 || c1 == c2) return false;
	return true;
}

int CTSP(vector<int> path, int visited){
	auto iter = dp.find(path);
	if(iter != dp.end()) return iter->second;

	int ret = 0;
	if(path.size() == N){
		ret = c[path.back()][path[0]];
		for(int i=0; i<N; i++){
			int u1 = path[i], v1 = path[(i+1)%N];
			for(int j=i+1; j<N; j++){
				int u2 = path[j], v2 = path[(j+1)%N];
				if(intersection(x[u1], y[u1], x[v1], y[v1], x[u2], y[u2], x[v2], y[v2])) ret += C;
			}
		}
	}
	else{
		ret = INF;
		int curr = path.back();
		path.push_back(-1);
		for(int next=1; next<N; next++){
			if(visited & 1<<next);
			else{
				path[path.size()-1] = next;
				ret = min(ret, CTSP(path, visited | 1<<next) + c[curr][next]);
			}
		}
	}
	dp[path] = ret;
	return ret;
}

int main(){
	for(int t=1; ; t++){
		scanf("%d %d", &N, &C);
		if(N == 0) break;

		for(int i=0; i<N; i++)
			scanf("%d %d", x+i, y+i);
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				scanf("%d", &c[i][j]);
		dp.clear();
		printf("%d. %d\n", t, CTSP(vector<int>(1, 0), 1));
	}
}