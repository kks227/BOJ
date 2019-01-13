#include <cstdio>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int MAX = 50000;
const int MAX_ST = 1<<17;
const int INF = 1e9;

struct SegTree{
	int A[MAX_ST], B[MAX_ST]; // min, max

	SegTree(){
		fill(A, A+MAX_ST, INF);
		fill(B, B+MAX_ST, -INF);
	}

	void set(int n, int k){
		n += MAX_ST/2;
		A[n] = min(k, A[n]);
		B[n] = max(k, B[n]);
	}

	void construct(){
		for(int i = MAX_ST/2-1; i > 0; --i){
			A[i] = min(A[i*2], A[i*2+1]);
			B[i] = max(B[i*2], B[i*2+1]);
		}
	}

	int getMin(int s, int e){ return getMin(s, e, 1, 0, MAX_ST/2); }
	int getMin(int s, int e, int node, int ns, int ne){
		if(e <= ns || ne <= s) return INF;
		if(s <= ns && ne <= e) return A[node];
		int mid = (ns+ne)/2;
		return min(getMin(s, e, node*2, ns, mid), getMin(s, e, node*2+1, mid, ne));
	}

	int getMax(int s, int e){ return getMax(s, e, 1, 0, MAX_ST/2); }
	int getMax(int s, int e, int node, int ns, int ne){
		if(e <= ns || ne <= s) return -INF;
		if(s <= ns && ne <= e) return B[node];
		int mid = (ns+ne)/2;
		return max(getMax(s, e, node*2, ns, mid), getMax(s, e, node*2+1, mid, ne));
	}
};



int main(){
	int N, x[MAX], y[MAX];
	set<int> xS, yS;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%d %d", x+i, y+i);
		xS.insert(x[i]);
		yS.insert(y[i]);
	}

	int X = 0, Y = 0, H2X[MAX], H2Y[MAX];
	unordered_map<int, int> X2H, Y2H;
	for(int x: xS){
		H2X[X] = x;
		X2H[x] = X++;
	}
	for(int y: yS){
		H2Y[Y] = y;
		Y2H[y] = Y++;
	}

	SegTree ST[2];
	for(int i = 0; i < N; ++i){
		x[i] = X2H[x[i]];
		y[i] = Y2H[y[i]];
		ST[0].set(x[i], y[i]);
		ST[1].set(y[i], x[i]);
	}
	ST[0].construct();
	ST[1].construct();

	long long res1 = 1LL * (H2X[X-1]-H2X[0]) * (H2Y[Y-1]-H2Y[0]), res2 = res1;
	for(int i = 0; i < X-1; ++i){
		int w1 = H2X[i] - H2X[0];
		int w2 = H2X[X-1] - H2X[i+1];
		int h1 = H2Y[ST[0].getMax(0, i+1)] - H2Y[ST[0].getMin(0, i+1)];
		int h2 = H2Y[ST[0].getMax(i+1, X)] - H2Y[ST[0].getMin(i+1, X)];
		res2 = min(1LL*w1*h1 + 1LL*w2*h2, res2);
	}
	for(int i = 0; i < Y-1; ++i){
		int w1 = H2X[ST[1].getMax(0, i+1)] - H2X[ST[1].getMin(0, i+1)];
		int w2 = H2X[ST[1].getMax(i+1, Y)] - H2X[ST[1].getMin(i+1, Y)];
		int h1 = H2Y[i] - H2Y[0];
		int h2 = H2Y[Y-1] - H2Y[i+1];
		res2 = min(1LL*w1*h1 + 1LL*w2*h2, res2);
	}
	printf("%lld\n", res1-res2);
}