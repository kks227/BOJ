#include <cstdio>
using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	for(int i=1, k=0; ; k+=i++){
		if(N > k && N <= k+i){
			int j = i-N+k+1;
			printf("%d %d\n", j, i+1-j);
			break;
		}
	}
}