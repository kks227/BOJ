#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int INF = 1e9+1;
const int MAX = 300001;

int main(){
	int N;
	scanf("%d", &N);
	P C[MAX];
	for(int i=0; i<N; i++){
		int x, r;
		scanf("%d %d", &x, &r);
		C[i] = P(x-r, x+r);
	}
	C[N++] = P(-INF, INF);
	sort(C, C+N, [](P& p, P& q){
		if(p.first != q.first) return p.first < q.first;
		return p.second > q.second;
	});

	int result = 1, S = 0, lo[MAX] = {-INF}, j[MAX] = {0};
	bool cont[MAX] = {false};
	for(int i=1; i<N; i++){
		while(C[i].first >= C[j[S]].second){
			result++;
			if(lo[S] == C[j[S]].second) result++;
			S--;
		}
		if(cont[S] && lo[S] == C[i].first) lo[S] = C[i].second;
		else cont[S] = false;
		j[++S] = i;
		cont[S] = true;
		lo[S] = C[i].first;
	}
	while(S > 0){
		result++;
		if(lo[S] == C[j[S]].second) result++;
		S--;
	}
	printf("%d\n", result);
}