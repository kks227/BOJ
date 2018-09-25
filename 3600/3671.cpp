#include <cstdio>
#include <numeric>
#include <unordered_set>
#include <algorithm>
using namespace std;
const int MAX_P = 1e7;

int main(){
	bool isP[MAX_P];
	fill(isP+2, isP+MAX_P, true);
	for(int i=4; i<MAX_P; i+=2)
		isP[i] = false;
	for(int i=3; i<MAX_P; i+=2){
		if(!isP[i]) continue;
		for(long long j=1LL*i*i; j<MAX_P; j+=i*2)
			isP[j] = false;
	}

	int T;
	scanf("%d\n", &T);
	for(int t=0; t<T; t++){
		int N, d[7], p[7], result = 0;
		for(N=0; ; N++){
			char c = getchar();
			if(c == '\n') break;
			d[N] = c - '0';
		}
		iota(p, p+N, 0);
		unordered_set<int> S;
		do{
			int temp = 0;
			for(int i=0; i<N; i++){
				temp = temp*10 + d[p[i]];
				S.insert(temp);
			}
		}while(next_permutation(p, p+N));
		for(int s: S)
			if(isP[s]) result++;
		printf("%d\n", result);
	}
}