#include <cstdio>
using namespace std;

int main(){
	long long koong[68] = {1, 1, 2, 4};
	for(int i=4; i<68; i++)
		koong[i] = koong[i-1]+koong[i-2]+koong[i-3]+koong[i-4];
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N;
		scanf("%d", &N);
		printf("%lld\n", koong[N]);
	}
}