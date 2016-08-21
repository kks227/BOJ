#include <cstdio>
using namespace std;

int main(){
	int N, L;
	scanf("%d %d", &N, &L);
	for(int i=L; i<=100; i++){
		if((N-i*(i+1)/2) % i == 0){
			int j = (N-i*(i+1)/2) / i + 1;
			if(j >= 0){
				for(int k=0; k<i; k++)
					printf("%d ", k+j);
				return 0;
			}
		}
	}
	puts("-1");
}