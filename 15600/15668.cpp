#include <cstdio>
using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	for(int A=1; A<100000 && A<N; A++){
		int a = A, b = N-A;
		bool used[10] = {0}, flag = true;
		do{
			if(used[a%10]){
				flag = false;
				break;
			}
			used[a%10] = true;
			a /= 10;
		}while(a);
		do{
			if(used[b%10]){
				flag = false;
				break;
			}
			used[b%10] = true;
			b /= 10;
		}while(b);
		if(flag){
			printf("%d + %d\n", A, N-A);
			return 0;
		}
	}
	puts("-1");
}