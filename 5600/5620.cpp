#include <cstdio>
#include <climits>
#include <cmath>
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
	int d = min(closestPair(l, mid), closestPair(mid, r)), result = d;
	double sd = sqrt(d);
	int S = copy(lower_bound(p+l, p+r, P(ceil(xp-sd), -INF)), upper_bound(p+l, p+r, P(floor(xp+sd), INF)), q) - q;
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
		scanf("%d %d", &p[i].second, &p[i].first);
	sort(p, p+N);
	printf("%d\n", closestPair(0, N));
}