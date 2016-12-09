#include <cstdio>
#include <bitset>
using namespace std;

int main(){
	bitset<1<<25> S;
	int A;
	while(scanf("%d", &A) > 0){
		if(!S.test(A)){
			printf("%d ", A);
			S.set(A);
		}
	}
}