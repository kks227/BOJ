#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_ST = 1<<20;
const int MAX_C = 10000;

struct MergesortTree{
	vector<int> arr[MAX_ST];

	void construct(){
		for(int i = MAX_ST/2-1; i > 0; --i){
			vector<int> &c = arr[i], &l = arr[i*2], &r = arr[i*2+1];
			arr[i].resize(l.size()+r.size());
			for(int j = 0, p = 0, q = 0; j < c.size(); ++j){
				if(q == r.size() || (p < l.size() && l[p] < r[q])) c[j] = l[p++];
				else c[j] = r[q++];
			}
		}
	}
	void getMajors(vector<int> &candidate, int s, int e){
		return getMajors(candidate, s, e, 1, 0, MAX_ST/2);
	}
	void getMajors(vector<int> &candidate, int s, int e, int node, int ns, int ne){
		if(ne <= s || e <= ns) return;
		if(s <= ns && ne <= e){
			if(ne-ns == 1) candidate.push_back(arr[node][0]);
			else{
				int m = (ne-ns)/2;
				if(arr[node][m-1] == arr[node][m]) candidate.push_back(arr[node][m]);
			}
			return;
		}
		int mid = (ns+ne)/2;
		getMajors(candidate, s, e, node*2, ns, mid);
		getMajors(candidate, s, e, node*2+1, mid, ne);
	}
};

int main(){
	int N, C, Q;
	MergesortTree ST;
	vector<int> cPos[MAX_C];
	scanf("%d %d", &N, &C);
	for(int i = 0; i < N; ++i){
		int val;
		scanf("%d", &val);
		ST.arr[MAX_ST/2 + i].push_back(--val);
		cPos[val].push_back(i);
	}
	ST.construct();
	scanf("%d", &Q);
	for(int i = 0; i < Q; ++i){
		int s, e;
		scanf("%d %d", &s, &e);
		vector<int> candidate;
		ST.getMajors(candidate, --s, e);
		bool r1 = false;
		int r2 = -1;
		for(int k: candidate){
			if(lower_bound(cPos[k].begin(), cPos[k].end(), e) - lower_bound(cPos[k].begin(), cPos[k].end(), s) > (e-s)/2){
				r1 = true;
				r2 = k+1;
				break;
			}
		}
		if(r1) printf("yes %d\n", r2);
		else puts("no");
	}
}