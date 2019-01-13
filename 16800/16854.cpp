#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 5000;
const int MAX_ST = 1<<14;
const int INF = 1e9;

int N;
char S[MAX+1], dp[MAX][MAX];

bool symm(int s, int e){
	char &ret = dp[s][e];
	if(ret != -1) return ret;
	if((e-s)%2 == 0) return ret = false;
	if(S[s] == S[e]) return ret = false;
	return ret = (s+1 == e ? true : symm(s+1, e-1));
}

struct SegTree{
	int A[MAX_ST];
	SegTree(){ fill(A, A+MAX_ST, INF); }
	void construct(){
		for(int i = MAX_ST/2-1; i > 0; --i)
			A[i] = min(A[i*2], A[i*2+1]);
	}
	int getMin(int s, int e){ return getMin(s, e, 1, 0, MAX_ST/2); }
	int getMin(int s, int e, int node, int ns, int ne){
		if(e <= ns || ne <= s) return INF;
		if(s <= ns && ne <= e) return A[node];
		int mid = (ns+ne)/2;
		return min(getMin(s, e, node*2, ns, mid), getMin(s, e, node*2+1, mid, ne));
	}
};



int main(){
	scanf("%s", S);
	N = strlen(S);
	memset(dp, -1, sizeof(dp));
	SegTree ST;
	int depth[MAX+1] = {0,};
	ST.A[MAX_ST/2] = 0;
	for(int i = 0; i < N; ++i){
		depth[i+1] += depth[i] + (S[i] == '(' ? 1 : -1);
		ST.A[MAX_ST/2 + i+1] = depth[i+1];
	}
	ST.construct();

	int result = 0;
	for(int i = 0; i < N; ++i)
		for(int j = i+1; j < N; j += 2)
			if(symm(i, j) && depth[i] == depth[j+1] && ST.getMin(i, j+1) >= depth[i]) ++result;
	printf("%d\n", result);
}