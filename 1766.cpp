#include <cstdio>
#include <queue>
#include <set>
using namespace std;

typedef set<int> intSet;

intSet predecessor[32000], successor[32000];

int main(){

	int N, M, u, v, current;
	scanf("%d %d", &N, &M);
	priority_queue< int, vector<int>, greater<int> > candidate;
	for(int i=0; i<M; i++){
		scanf("%d %d", &u, &v);
		predecessor[v-1].insert(u-1);
		successor[u-1].insert(v-1);
	}
	for(int i=0; i<N; i++)
		if(predecessor[i].empty()) candidate.push(i);
	while(!candidate.empty()){
		current = candidate.top();
		candidate.pop();
		printf("%d ", current+1);
		for(intSet::iterator iter=successor[current].begin(); iter!=successor[current].end(); iter++){
			iter = iter++;
			predecessor[*iter].erase(current);
			if(predecessor[*iter].empty()) candidate.push(*iter);
		}
	}

	return 0;
}