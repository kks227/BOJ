#include <cstdio>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <functional>
using namespace std;
const int INF = 1e9;
const int ST_MAX = 1<<18;
typedef tuple<int, int, int> RectTuple;

struct Rect{
	int x1, y1, x2, y2;
	Rect(): Rect(0, 0, 0, 0){}
	Rect(int x3, int y3, int x4, int y4): x1(x3), y1(y3), x2(x4), y2(y4){}
	bool operator <(const Rect &O){
		if(x1 != O.x1) return x1 < O.x1;
		return y1 > O.y1;
	}
};

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
	int N;
	Rect R[100000];
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		R[i] = Rect(x1, y1, x2, y2);
	}
	sort(R, R+N);

	SegTree ST;
	int result = 0;
	priority_queue<RectTuple, vector<RectTuple>, greater<RectTuple>> PQ;
	for(int i=0, j=0; i<=100000 && j<N; i++){
		while(R[j].x1 < i) j++;
		if(j == N) break;
		for(; j<N && R[j].x1 == i; j++){
			int temp = ST.getMax(0, R[j].y1) + 1;
			result = max(temp, result);
			PQ.push(RectTuple(R[j].x2, R[j].y2, temp));
		}
		while(!PQ.empty()){
			int x, y, val;
			tie(x, y, val) = PQ.top();
			if(x != i) break;
			int temp = ST.arr[ST_MAX/2 + y];
			ST.update(y, max(temp, val));
			PQ.pop();
		}
	}
	printf("%d\n", result);
}