#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, side[11], result = 0;
	scanf("%d", &N);
	fill(side, side+11, -1);
	for(int i=0; i<N; i++){
		int n, s;
		scanf("%d %d", &n, &s);
		if(side[n] >= 0 && side[n] != s) result++;
		side[n] = s;
	}
	printf("%d\n", result);
}