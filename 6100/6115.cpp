#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

int main(){
	int N;
	vector<P> p;
	scanf("%d", &N);
	long long result = 0;
	for(int i=0; i<N; i++){
		int D, C;
		scanf("%d %d", &D, &C);
		if(D >= N) result += C;
		else p.push_back(P(D, C));
	}
	sort(p.begin(), p.end());

	priority_queue<int> PQ;
	for(int i=N-1, j=p.size()-1; i>0; i--){
		while(j >= 0 && p[j].first == i) PQ.push(p[j--].second);
		if(!PQ.empty()){
			result += PQ.top();
			PQ.pop();
		}
	}
	printf("%lld\n", result);
}