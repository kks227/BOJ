#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int x, y;
		scanf("%d %d", &x, &y);
		if(x == y){
			puts("0");
			continue;
		}

		long long sum = 0;
		for(int i=1; ; i++){
			sum += (i+1)/2;
			if(sum >= y-x){
				printf("%d\n", i);
				break;
			}
		}
	}
}