#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 1000;

int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; ++i){
		int H;
		scanf("%d", &H);
		M -= H + 1;
	}
	int result = 0;
	++N;
	for(int i = 1; M > 0; ++i){
		result += min(N, M)*i*i;
		M -= N;
	}
	printf("%d\n", result);
}