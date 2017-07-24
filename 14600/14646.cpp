#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, result = 0, cnt = 0;
	bool used[100000] = {0};
	scanf("%d", &N);
	for(int i=0; i<N*2; i++){
		int val;
		scanf("%d", &val);
		val--;
		if(!used[val]) result = max(result, ++cnt);
		else cnt--;
		used[val] = !used[val];
	}
	printf("%d\n", result);
}