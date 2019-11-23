#include <cstdio>
#include <vector>
using namespace std;
const int MAX = 1000000;

int main(){
	int N, A;
	vector<int> result;
	scanf("%d %d", &N, &A);
	result.push_back(A);
	for(int i = 1; i < N; ++i){
		scanf("%d", &A);
		if(A > result.back()) result.push_back(A);
	}
	printf("%d\n", result.size());
	for(int i: result)
		printf("%d ", i);
}