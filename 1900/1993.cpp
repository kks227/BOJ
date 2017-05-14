#include <cstdio>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
const int ST_MAX = 1<<15;

int N, K, x[32], y[32], w[32], score;
double d;
map<int, double> M[32];

inline double distance(int x1, int y1, int x2, int y2){
	return sqrt(pow(x1-x2, 2.0) + pow(y1-y2, 2.0));
}

void dfs(int pos, bool side){
	auto finder = M[pos].find(score);
	if(finder == M[pos].end()) M[pos][score] = d;
	else finder->second = min(finder->second, d);
	if(pos == K) return;

	double cd = d;
	if(side){
		for(int i=pos-1; i>K; i--){
			d = cd + distance(x[pos], y[pos], x[i], y[i]);
			score += w[i];
			dfs(i, side);
			d = cd;
			score -= w[i];
		}
	}
	else{
		for(int i=pos+1; i<=K; i++){
			d = cd + distance(x[pos], y[pos], x[i], y[i]);
			score += w[i];
			dfs(i, side);
			d = cd;
			score -= w[i];
		}
	}
}

struct SegTree{
	int arr[ST_MAX], start;
	SegTree(){
		start = ST_MAX/2;
		fill(arr, arr+ST_MAX, 0);
	}
	void update(int n, int k){
		arr[start+n] = max(arr[start+n], k);
	}
	void construct(){
		for(int i=start-1; i>0; i--)
			arr[i] = max(arr[i*2], arr[i*2+1]);
	}
	int getMax(int s, int e){
		return getMax(s, e, 1, 0, start);
	}
	int getMax(int s, int e, int node, int ns, int ne){
		if(ne <= s || e <= ns) return 0;
		if(s <= ns && ne <= e) return arr[node];
		int mid = (ns+ne)/2;
		return max(getMax(s, e, node*2, ns, mid), getMax(s, e, node*2+1, mid, ne));
	}
};



int main(){
	for(int t=1; ; t++){
		scanf("%d", &N);
		if(N == 0) break;

		x[0] = y[0] = w[0] = x[N+1] = y[N+1] = w[N+1] = 0;
		for(int i=1; i<=N; i++)
			scanf("%d %d %d", x+i, y+i, w+i);
		N += 2;
		K = N/2;
		dfs(0, false);
		dfs(N, true);
		SegTree ST; // dist - max score
		for(int i=0; i<=K; i++){
			for(int j=K+1; j<N; j++){
				double bridge = distance(x[i], y[i], x[j], y[j]);
				for(auto &p: M[i]){
					for(auto &q: M[j]){
						int d = ceil(p.second + q.second + bridge);
						int s = p.first + q.first;
						if(d <= 10000) ST.update(d, s);
					}
				}
			}
		}
		ST.construct();

		printf("Race %d\n", t);
		while(1){
			char name[61];
			int d;
			scanf("%s %d", name, &d);
			if(name[0] == '#') break;
			printf("%s: %d\n", name, ST.getMax(0, d+1));
		}

		score = d = 0;
		for(int i=0; i<32; i++)
			M[i].clear();
	}
}