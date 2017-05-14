#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

int main(){
	int N, M;
	multiset<int> T;
	P R[20000];
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		int t;
		scanf("%d", &t);
		T.insert(t);
	}
	for(int i=0; i<M; i++)
		scanf("%d %d", &R[i].first, &R[i].second);
	sort(R, R+M, [](const P& p, const P& q){
		if(p.second != q.second) return p.second < q.second;
		return p.first < q.first;
	});

	int result = 0;
	for(int i=0; i<M; i++){
		auto finder = T.lower_bound(R[i].first);
		if(finder != T.end() && *finder <= R[i].second){
			result++;
			T.erase(finder);
		}
	}
	printf("%d\n", result);
}