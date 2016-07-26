#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int A, B;
		scanf("%d %d", &A, &B);
		if(A<B) swap(A, B);
		int result = 1, n = 1;
		while(1){
			if((1<<n)-1 > A+B) break;
			if((1<<n)-1 <= B) result += 1<<n;
			else if((1<<n)-1 <= A) result += B+1;
			else result += A+B+2-(1<<n);
			n++;
		}
		printf("%d\n", result);
	}
}