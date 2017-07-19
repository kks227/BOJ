#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main(){
	int N, M;
	vector<int>input;
	priority_queue<int> sort;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", &M);
		sort.push(M);
	}
	for(int i=0; i<N; i++){
		input.push_back(sort.top());
		sort.pop();
	}
	printf("%lld\n", 1LL*input[N/2-!(N%2)]*input[N/2]);
}