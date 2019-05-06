#include <cstdio>
using namespace std;

int main(){
	int N, result = 0;
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i){
		int val;
		scanf("%d", &val);
		if(val != i) ++result;
	}
	printf("%d\n", result);
}