#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1<<18;

struct SegTree{
	vector<int> arr[MAX];

	SegTree(){}
	void construct(){
		for(int i=MAX/2-1; i>0; i--){
			vector<int> &c = arr[i], &l = arr[i*2], &r = arr[i*2+1];
			arr[i].resize(l.size()+r.size());
			for(int j=0, p=0, q=0; j<c.size(); j++){
				if(q == r.size() || (p < l.size() && l[p] < r[q])) c[j] = l[p++];
				else c[j] = r[q++];
			}
		}
	}
	int greater(int s, int e, int k, int node=1, int ns=0, int ne=MAX/2){
		if(ne <= s || e <= ns) return 0;
		if(s <= ns && ne <= e)
			return arr[node].end() - upper_bound(arr[node].begin(), arr[node].end(), k);
		int mid = (ns+ne)/2;
		return greater(s, e, k, node*2, ns, mid) + greater(s, e, k, node*2+1, mid, ne);
	}
};

int main(){
	int N, M, L = 0;
	SegTree ST;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int val;
		scanf("%d", &val);
		ST.arr[MAX/2+i].push_back(val);
	}
	ST.construct();
	scanf("%d", &M);
	for(int i=0; i<M; i++){
		int s, e, k;
		scanf("%d %d %d", &s, &e, &k);
		printf("%d\n", L=ST.greater((s^L)-1, e^L, k^L));
	}
}