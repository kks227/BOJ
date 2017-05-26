#include <cstdio>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

int main(){
	int N;
	scanf("%d", &N);
	set<P> S;
	for(int i=0; i<N; i++){
		int H;
		scanf("%d", &H);
		S.insert(P(-H, i));
	}
	int result = 0;
	for(; !S.empty(); result++){
		int h = S.begin()->first, i = S.begin()->second;
		S.erase(S.begin());
		while(1){
			auto finder = S.lower_bound(P(h+1, i));
			if(finder == S.end() || finder->first > h+1) break;
			h++; i = finder->second;
			S.erase(finder);
		}
	}
	printf("%d\n", result);
}