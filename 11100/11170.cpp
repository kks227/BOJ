#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int result = 0, N, M;
		scanf("%d %d", &N, &M);
		for(int i=N; i<=M; i++){
			int temp = i;
			do{
				if(temp%10 == 0) result++;
				temp /= 10;
			}while(temp);
		}
		printf("%d\n", result);
	}
}