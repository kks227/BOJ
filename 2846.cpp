#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, cur, prev = 1000, lo = 1000, result = 0;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", &cur);
		if(prev >= cur){
			result = max(result, prev-lo);
			lo = cur;
		}
		prev = cur;
	}
	result = max(result, prev-lo);
	printf("%d\n", result);
}