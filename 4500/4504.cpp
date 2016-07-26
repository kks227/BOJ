#include <cstdio>
using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	while(1){
		int val;
		scanf("%d", &val);
		if(val == 0) break;
		printf("%d is %sa multiple of %d.\n", val, val%N ? "NOT " : "", N);
	}
}