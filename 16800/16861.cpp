#include <cstdio>
using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	for(int i = N; ; ++i){
		int sum = 0, j = i;
		while(j > 0){
			sum += j%10;
			j /= 10;
		}
		if(i%sum == 0){
			printf("%d\n", i);
			break;
		}
	}
}