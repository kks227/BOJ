#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	int S, P;
	scanf("%d %d", &S, &P);
	if(S == P){
		puts("1");
		return 0;
	}
	double prev = -1;
	for(int result=2; ; result++){
		double curr = pow(1.0*S/result, result);
		if(prev > curr){
			puts("-1");
			return 0;
		}
		if(P <= curr){
			printf("%d\n", result);
			return 0;
		}
		prev = curr;
	}
}