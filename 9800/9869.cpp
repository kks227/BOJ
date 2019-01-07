#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 10000;

int main(){
	int N;
	vector<int> C[MAX];
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		int g, d;
		scanf("%d %d", &g, &d);
		C[d-1].push_back(g);
	}

	int result = 0;
	priority_queue<int> PQ;
	for(int i = MAX-1; i >= 0; --i){
		for(int g: C[i])
			PQ.push(g);
		if(!PQ.empty()){
			result += PQ.top();
			PQ.pop();
		}
	}
	printf("%d\n", result);
}