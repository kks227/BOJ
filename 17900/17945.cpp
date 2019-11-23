#include <cstdio>
using namespace std;

int main(){
	int A, B;
	scanf("%d %d", &A, &B);
	for(int i = -1000; i <= 1000; ++i){
		for(int j = i; j <= 1000; ++j){
			if(i+j == -2*A && i*j == B){
				if(i == j) printf("%d\n", i);
				else printf("%d %d\n", i, j);
				return 0;
			}
		}
	}
}