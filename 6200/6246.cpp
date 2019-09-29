#include <cstdio>
using namespace std;
const int MAX = 10000;

int main(){
	int N, Q, result = 0;
	scanf("%d %d", &N, &Q);
	bool fill[MAX] = {false,};
	for(int q = 0; q < Q; ++q){
		int s, k;
		scanf("%d %d", &s, &k);
		for(--s; s < N; s += k)
			fill[s] = true;
	}
	for(int i = 0; i < N; ++i)
		if(!fill[i]) ++result;
	printf("%d\n", result);
}