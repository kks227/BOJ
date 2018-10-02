#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <tuple>
#include <algorithm>
#include <functional>
using namespace std;
const int ST_MAX = 1<<19;
const int INF = 1e9;
typedef pair<int, int> PtrPair;
typedef tuple<int, int, int> PtrTuple;

struct SegTree{
	int arr[ST_MAX];
	SegTree(){ fill(arr, arr+ST_MAX, 0); }
	void update(int n, int k){
		n += ST_MAX/2;
		arr[n] = k;
		while(n > 1){
			n /= 2;
			arr[n] = max(arr[n*2], arr[n*2+1]);
		}
	}
	int getMax(int s, int e){ return getMax(s, e, 1, 0, ST_MAX/2); }
	int getMax(int s, int e, int node, int ns, int ne){
		if(e <= ns || ne <= s) return 0;
		if(s <= ns && ne <= e) return arr[node];
		int mid = (ns+ne)/2;
		return max(getMax(s, e, node*2, ns, mid), getMax(s, e, node*2+1, mid, ne));
	}
};

int main(){
	int N, L, X[200000], Y[200000], B[200000], xo[200000], yo[200000];
	PtrTuple ptr[200000];
	set<int> SX, SY;
	scanf("%d %d", &N, &L);
	for(int i=0; i<N; i++){
		int x, y, b;
		scanf("%d %d %d", &x, &y, &b);
		ptr[i] = PtrTuple(x, y, b);
		SX.insert(x);
		SY.insert(y);
	}
	sort(ptr, ptr+N, [](PtrTuple P, PtrTuple Q){
		get<1>(P) *= -1;
		get<1>(Q) *= -1;
		return P < Q;
	});
	int xcnt = 0, ycnt = 0;
	map<int, int> xc, yc;
	for(int x: SX){
		xo[xcnt] = x;
		xc[x] = xcnt++;
	}
	for(int y: SY){
		yo[ycnt] = y;
		yc[y] = ycnt++;
	}
	for(int i=0; i<N; i++){
		X[i] = xc[get<0>(ptr[i])];
		Y[i] = yc[get<1>(ptr[i])];
		B[i] = get<2>(ptr[i]);
	}

	SegTree ST;
	int result = 0;
	multiset<int> dp[200000];
	priority_queue<PtrTuple, vector<PtrTuple>, greater<PtrTuple>> PQ;
	for(int i = 0, j = 0; i < 200000 && j < N; i++){
		while(!PQ.empty()){
			int x, y, val;
			tie(x, y, val) = PQ.top();
			if(x >= xo[i]) break;

			dp[y].erase(dp[y].find(val));
			int temp = 0;
			if(!dp[y].empty()){
				auto iter = dp[y].end();
				temp = *(--iter);
			}
			ST.update(y, temp);
			PQ.pop();
		}

		for(; j < N && X[j] == i; j++){
			int ypos = lower_bound(yo, yo+ycnt, yo[Y[j]]-L) - yo;
			int temp = ST.getMax(yc[yo[ypos]], Y[j]) + B[j];
			result = max(temp, result);
			dp[Y[j]].insert(temp);
			auto iter = dp[Y[j]].end();
			if(*(--iter) == temp) ST.update(Y[j], temp);
			PQ.push(PtrTuple(xo[i]+L, Y[j], temp));
		}
	}
	printf("%d\n", result);
}