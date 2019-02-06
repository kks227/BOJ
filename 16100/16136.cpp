#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
const int MAX = 100000;
const int MAX_P = 1000001;
const int MAX_ST = 1<<18;

struct SegTree{
	long long A[MAX_ST];
	SegTree(){ fill(A, A+MAX_ST, 0); }
	void update(int n, long long k){
		n += MAX_ST/2;
		A[n] = k;
		while(n > 1){
			n /= 2;
			A[n] = A[n*2] + A[n*2+1];
		}
	}
	void construct(){
		for(int i = MAX_ST/2-1; i > 0; --i)
			A[i] = A[i*2] + A[i*2+1];
	}
	long long sum(int s, int e){ return sum(s, e, 1, 0, MAX_ST/2); }
	long long sum(int s, int e, int node, int ns, int ne){
		if(e <= ns || ne <= s) return 0;
		if(s <= ns && ne <= e) return A[node];
		int mid = (ns+ne)/2;
		return sum(s, e, node*2, ns, mid) + sum(s, e, node*2+1, mid, ne);
	}
};

int cnt[MAX_P];
bool np[MAX_P] = {true, true,}, sqp[MAX_P];
vector<int> prime;

int cntFactor(int n, int s = 0){
	int &ret = cnt[n];
	if(ret > 0) return ret;
	if(n == 1) return ret = 1;
	if(!np[n]) return ret = 2;
	if(sqp[n]) return ret = 3;

	for(int i = s; i < prime.size(); ++i){
		int &p = prime[i];
		if(n%p) continue;

		int temp = 0;
		do{
			++temp;
			n /= p;
		}while(n%p == 0);
		return ret = (temp+1) * cntFactor(n, i+1);
	}
	return ret = 1;
}



int main(){
	for(int i = 4; i < MAX_P; i += 2)
		np[i] = true;
	prime.push_back(2);
	sqp[1] = sqp[4] = true;
	for(int i = 3; i < MAX_P; i += 2){
		if(np[i]) continue;
		prime.push_back(i);
		long long j = 1LL*i*i;
		if(j < MAX_P) sqp[j] = true;
		for(; j < MAX_P; j += i*2)
			np[j] = true;
	}

	int N, Q;
	SegTree ST;
	set<int> S;
	scanf("%d %d", &N, &Q);
	for(int i = 0; i < N; ++i){
		int val;
		scanf("%d", &val);
		ST.A[MAX_ST/2 + i] = val;
		if(val > 2) S.insert(i);
	}
	ST.construct();

	for(int i = 0; i < Q; ++i){
		int o, s, e;
		scanf("%d %d %d", &o, &s, &e);
		--s;
		if(o == 1){
			auto iter = S.lower_bound(s);
			while(iter != S.end() && *iter < e){
				int j = *iter, k = cntFactor(ST.A[MAX_ST/2 + j]);
				ST.update(j, k);
				if(k <= 2){
					auto tempIter = iter;
					++tempIter;
					S.erase(iter);
					iter = tempIter;
				}
				else ++iter;
			}
		}
		else printf("%lld\n", ST.sum(s, e));
	}
}