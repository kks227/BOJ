#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

int main(){
	int N, A, D;
	P pos[20000];
	scanf("%d %d %d", &N, &A, &D);
	for(int i=0; i<N; i++){
		int val;
		scanf("%d", &val);
		pos[i] = P(val, i);
	}
	sort(pos, pos+N);

	int result = 0, curr = -1;
	while(1){
		auto iter = upper_bound(pos, pos+N, P(A + D*result, curr));
		if(iter == pos+N || iter->first > A + D*result) break;
		curr = iter->second;
		result++;
	}
	printf("%d\n", result);
}