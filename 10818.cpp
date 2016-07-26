#include <cstdio>
using namespace std;

int main(){
	int N, max=-1000000, min=1000000;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int n;
		scanf("%d", &n);
		if(max < n) max = n;
		if(min > n) min = n;
	}
	printf("%d %d\n", min, max);
}