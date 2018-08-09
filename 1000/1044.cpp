#include <cstdio>
#include <cmath>
#include <set>
#include <algorithm>
#include <utility>
using namespace std;
const long long INF = 1e18;
typedef pair<long long, long long> P;

int N;
long long score[2][36], scale;
P result = P(INF, 0);
set<P> S[19];

void dfs1(int pos, int status, int cnt, long long s1, long long s2){
	if(pos == N/2){
		S[cnt].insert(P(s1-s2, status));
		return;
	}
	dfs1(pos+1, status*2, cnt, s1+score[0][pos], s2);
	dfs1(pos+1, status*2+1, cnt+1, s1, s2+score[1][pos]);
}

void dfs2(int pos, int status, int cnt, long long s1, long long s2){
	if(pos == N/2){
		auto finder = S[N/2-cnt].lower_bound(P(s2-s1, -INF));
		if(finder != S[N/2-cnt].end()){
			result = min(P(abs(finder->first + s1-s2), finder->second*scale + status), result);
		}
		if(finder != S[N/2-cnt].begin()){
			finder--;
			finder = S[N/2-cnt].lower_bound(P(finder->first, -INF));
			result = min(P(abs(finder->first + s1-s2), finder->second*scale + status), result);
		}
		return;
	}
	dfs2(pos+1, status*2, cnt, s1+score[0][pos+N/2], s2);
	dfs2(pos+1, status*2+1, cnt+1, s1, s2+score[1][pos+N/2]);
}

int main(){
	scanf("%d", &N);
	scale = 1LL<<(N/2);
	for(int i=0; i<2; i++)
		for(int j=0; j<N; j++)
			scanf("%lld", &score[i][j]);
	dfs1(0, 0, 0, 0, 0);
	dfs2(0, 0, 0, 0, 0);
	for(int i=0; i<N; i++)
		printf("%d ", result.second & 1LL<<(N-i-1) ? 2 : 1);
}