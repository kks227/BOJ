#include <cstdio>
#include <tuple>
#include <algorithm>
using namespace std;
const int MAX = 50000;
typedef tuple<int, int, int> Node;

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t){
		int N;
		Node p[MAX];
		scanf("%d", &N);
		for(int i = 0; i < N; ++i){
			int d, s, e;
			scanf("%d %d %d", &d, &s, &e);
			p[i] = Node(d, e, s);
		}
		sort(p, p+N);
		int result = 0, s = 0, e = 0;
		while(s < N){
			for(e = s+1; e < N && get<0>(p[s]) == get<0>(p[e]); ++e);
			int curr = get<1>(p[s]);
			++result;
			for(int i = s+1; i < e; ++i){
				if(curr <= get<2>(p[i])){
					curr = get<1>(p[i]);
					++result;
				}
			}
			s = e;
		}
		printf("Scenario #%d:\n%d\n\n", t, result);
	}
}