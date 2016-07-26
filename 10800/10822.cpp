#include <cstdio>
using namespace std;

int main(){
	int n, sum = 0;
	while(scanf("%d,", &n)>0){
		sum += n;
	}
	printf("%d\n", sum);
}