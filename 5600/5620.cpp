#include <cstdio>
#include <fstream>
#include <string>
#include <climits>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int MAX = 500000;
const int INF = INT_MAX;

int N;
P p[MAX], q[MAX];

inline int d2(P &a, P &b){
	return (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);
}

int closestPair(int l, int r){
	if(r-l <= 3){
		int result = INF;
		for(int i=l; i<r-1; i++)
			for(int j=i+1; j<r; j++)
				result = min(result, d2(p[i], p[j]));
		return result;
	}

	int mid = (l+r)/2, xp = p[mid-1].first;
	int d = min(closestPair(l, mid), closestPair(mid, r));
	int result = d;
	P *lp = lower_bound(p+l, p+r, P(xp-d, -INF)), *rp = upper_bound(p+l, p+r, P(xp+d, INF));
	int S = copy(lp, rp, q) - q;
	sort(q, q+S, [](P &a, P &b){
		if(a.second != b.second) return a.second < b.second;
		return a.first < b.first;
	});
	for(int i=0; i<S; i++)
		for(int j=1; j<12 && i+j<S; j++)
			result = min(result, d2(q[i], q[i+j]));
	return result;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d %d", &p[i].first, &p[i].second);
	sort(p, p+N);
	printf("%d\n", closestPair(0, N));
}