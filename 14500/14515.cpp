#include <cstdio>
#include <cmath>
using namespace std;
const int MAX = 100000;

int main(){
	int N = 0, pSum[MAX+1][2] = {0,};
	while(1){
		char c = getchar();
		if(c == '\n') break;
		int k = (c == 'B');
		for(int i = 0; i < 2; ++i)
			pSum[N+1][i] = pSum[N][i] + (i == k);
		++N;
	}
	if(N%2 == 1){
		puts("0");
		return 0;
	}
	for(int i = 1; i < N; i += 2){
		if(abs(pSum[i][0]-pSum[i][1]) == 1 && abs(pSum[N][0]+pSum[N][1]-pSum[i][0]-pSum[i][1]) == 1){
			puts("1");
			return 0;
		}
	}
	puts("0");
}