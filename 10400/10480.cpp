#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		int N;
		scanf("%d", &N);
		printf("%d is %s\n", N, (N%2 ? "odd" : "even"));
	}
}