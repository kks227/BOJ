#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int sum = 0;
		while(1){
			int N, c;
			if(scanf("%d", &N) <= 0) break;
			sum += N;
			c = getchar();
			if(c=='\n') break;
		}
		printf("%d\n", sum);
	}
}