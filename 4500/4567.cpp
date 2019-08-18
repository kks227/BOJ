#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 17;
const int INF = 1e9;
typedef pair<int, int> P;

class Wizards{
public:
	Wizards(): Wizards(0){}
	Wizards(int N1): N(N1){}

	void input(){
		for(int i = 0; i < N; ++i){
			char c;
			int K;
			scanf(" %c %d", &c, &K);
			fill(d[i], d[i]+N, INF);
			d[i][i] = 0;
			for(int j = 0; j < K; ++j){
				int k;
				scanf(" %c %d", &c, &k);
				d[i][c-'A'] = k;
				adj[i].push_back(P(c-'A', k));
			}
		}
	}

	void solve(){
		for(int k = 0; k < N; ++k)
			for(int i = 0; i < N; ++i)
				for(int j = 0; j < N; ++j)
					d[i][j] = min(d[i][k] + d[k][j], d[i][j]);

		int result = INF;
		for(status = 0; status < (1<<N); ++status){
			int bcnt = 0;
			for(int i = 0; i < N; ++i)
				if((1<<i) & status) ++bcnt;
			if(bcnt >= result) continue;
			fill(dp, dp+N, -1);
			if(mark(0)) result = bcnt;
		}
		printf("%d %d\n", d[0][N-1], result);
	}

private:
	int N, d[MAX][MAX], status;
	vector<P> adj[MAX];
	char dp[MAX];

	bool mark(int curr){
		char &ret = dp[curr];
		if(ret != -1) return ret;
		if(curr == N-1) return ret = true;

		if((1<<curr) & status){
			for(auto& p: adj[curr]){
				int next = p.first, w = p.second;
				if(d[curr][N-1] == d[next][N-1] + w && mark(next)) return ret = true;
			}
			return ret = false;
		}
		else{
			for(auto& p: adj[curr]){
				int next = p.first, w = p.second;
				if(d[curr][N-1] != d[next][N-1] + w || !mark(next)) return ret = false;
			}
			return ret = true;
		}
		return ret; // dummy
	}
};



int main(){
	while(1){
		int N;
		scanf("%d", &N);
		if(N == 0) break;

		Wizards solver(N);
		solver.input();
		solver.solve();
	}
}