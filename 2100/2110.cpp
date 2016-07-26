#include <cstdio>
#include <algorithm>
using namespace std;

int N, C, x[200000], limit;

bool possible(int current, int remain){
	if(remain == 0) return true;
	for(int i=current+1; i<N; i++)
		if(x[i]-x[current] >= limit) return possible(i, remain-1);
	return false;
}

int main(){
	scanf("%d %d", &N, &C);
	for(int i=0; i<N; i++)
		scanf("%d", x+i);
	sort(x, x+N);

	int upper = x[N-1]+1, lower = 1;
	while(lower+1 < upper){
		limit = (upper+lower)/2;
		if(possible(0, C-1)) lower = limit;
		else upper = limit;
	}
	printf("%d\n", lower);
}