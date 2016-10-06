#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 1<<18;
typedef pair<int, int> P;

struct SegTree{
	long long arr[MAX];
	int start;
	SegTree(): start(MAX/2){ fill(arr, arr+MAX, 0); }
	void inc(int n){
		n += start;
		arr[n] = 1;
		while(n > 1){
			n /= 2;
			arr[n] = arr[n*2] + arr[n*2+1];
		}
	}
	long long sum(int s, int e){ return sum(s, e, 1, 0, start); }
	long long sum(int s, int e, int node, int ns, int ne){
		if(e <= ns || ne <= s) return 0;
		if(s <= ns && ne <= e) return arr[node];
		int mid = (ns+ne)/2;
		return sum(s, e, node*2, ns, mid) + sum(s, e, node*2+1, mid, ne);
	}
};

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		SegTree ST;
		int N;
		scanf("%d", &N);
		P p[100000];
		for(int i=0; i<N; i++){
			scanf("%d", &p[i].first);
			p[i].second = i;
		}
		sort(p, p+N);

		long long result = 0;
		for(int i=0; i<N; i++){
			int val;
			scanf("%d", &val);
			val--;
			result += ST.sum(p[val].second, N);
			ST.inc(p[val].second);
		}
		printf("%lld\n", result);
	}
}