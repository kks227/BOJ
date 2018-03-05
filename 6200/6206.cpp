#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int MAX = 1<<15;
const int MAX_VAL = 1000001;
const int INF = 1e9;

struct SuffixNode{
	int sa;
	P rank;
	bool operator <(const SuffixNode &O)const{ return rank < O.rank; }
};

struct SuffixArray{
	int S[MAX], N, sa[MAX], pos[MAX], lcp[MAX];

	void constructSA(){
		SuffixNode node[MAX], nodeTemp[MAX];
		for(int i=0; i<N; i++){
			node[i].sa = i;
			node[i].rank = P(S[i], i<N-1 ? S[i+1] : -1);
		}
		sort(node, node+N);

		for(int d=2; d<N; d*=2){
			int M = 0, temp = node[0].rank.first;
			node[0].rank.first = pos[node[0].sa] = 0;

			for(int i=1; i<N; i++){
				if(P(temp, node[i-1].rank.second) == node[i].rank) node[i].rank.first = M;
				else{
					temp = node[i].rank.first;
					node[i].rank.first = ++M;
				}
				pos[node[i].sa] = i;
			}
			M++;

			int cnt[MAX_VAL+1] = {0};
			for(int i=0; i<N; i++){
				int j = node[i].sa + d;
				node[i].rank.second = (j < N ? node[pos[j]].rank.first : -1);
				cnt[node[i].rank.second+1]++;
			}
			for(int i=1; i<M+1; i++)
				cnt[i] += cnt[i-1];
			for(int i=N-1; i>=0; i--)
				nodeTemp[--cnt[node[i].rank.second+1]] = node[i];

			fill(cnt, cnt+M+1, 0);
			for(int i=0; i<N; i++)
				cnt[nodeTemp[i].rank.first]++;
			for(int i=1; i<M; i++)
				cnt[i] += cnt[i-1];
			for(int i=N-1; i>=0; i--)
				node[--cnt[nodeTemp[i].rank.first]] = nodeTemp[i];
		}

		for(int i=0; i<N; i++){
			sa[i] = node[i].sa;
			pos[sa[i]] = i;
		}
	}

	void constructLCP(){
		for(int i=0, k=0; i<N; i++, k=max(k-1, 0)){
			if(pos[i] == N-1) continue;
			for(int j=sa[pos[i]+1]; S[i+k]==S[j+k]; k++);
			lcp[pos[i]] = k;
		}
	}
};

struct SegTree{
	int arr[MAX*2];
	SegTree(){ fill(arr, arr+MAX*2, INF); }
	void construct(){
		for(int i=MAX-1; i>0; i--)
			arr[i] = min(arr[i*2], arr[i*2+1]);
	}
	int getMin(int s, int e){ return getMin(s, e, 1, 0, MAX); }
	int getMin(int s, int e, int node, int ns, int ne){
		if(e <= ns || ne <= s) return INF;
		if(s <= ns && ne <= e) return arr[node];
		int mid = (ns+ne)/2;
		return min(getMin(s, e, node*2, ns, mid), getMin(s, e, node*2+1, mid, ne));
	}
};

int main(){
	int N, K;
	SuffixArray SA;
	scanf("%d %d", &N, &K);
	SA.N = N;
	for(int i=0; i<N; i++)
		scanf("%d", SA.S+i);
	SA.constructSA();
	SA.constructLCP();

	SegTree ST;
	copy(SA.lcp, SA.lcp+N-1, ST.arr+MAX);
	ST.construct();
	int result = 0;
	for(int i=0; i+K-1<N; i++)
		result = max(result, ST.getMin(i, i+K-1));
	printf("%d\n", result);
}