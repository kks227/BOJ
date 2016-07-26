#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int H, W, N;
		scanf("%d %d %d", &H, &W, &N);
		N--;
		printf("%d\n", (N%H+1)*100+N/H+1);
	}
}