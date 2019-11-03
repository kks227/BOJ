#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_P = 1<<15;

int main(){
	bool np[MAX_P] = {true, true,};
	for(int i = 3; i < MAX_P; i += 2){
		if(np[i]) continue;
		for(long long j = 1LL*i*i; j < MAX_P; j += i*2)
			np[j] = true;
	}
	while(1){
		int N;
		scanf("%d", &N);
		if(N == 0) break;

		int result = 0;
		if(N/2%2 == 1 && !np[N/2] || N == 4) ++result;
		for(int i = 3; i*2 < N; i += 2)
			if(!np[i] && !np[N-i]) ++result;
		printf("%d\n", result);
	}
}