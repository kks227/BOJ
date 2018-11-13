#include <cstdio>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

int main(){
	int N;
	set<P> L;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		int s, e;
		scanf("%d %d", &s, &e);
		L.insert(P(s, e));
	}

	int s = -1, e, result = 0;
	for(auto &l: L){
		if(s == -1){
			s = l.first;
			e = l.second;
		}
		else{
			if(l.first > e){
				result += e-s;
				s = l.first;
				e = l.second;
			}
			else e = max(l.second, e);
		}
	}
	result += e-s;
	printf("%d\n", result);
}