#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_P = 1001;

int main(){
	bool np[MAX_P] = {true, false, true,};
	vector<int> prime;
	prime.push_back(1);
	prime.push_back(2);
	for(int i = 3; i < MAX_P; i += 2){
		if(np[i]) continue;
		prime.push_back(i);
		for(int j = i*i; j < MAX_P; j += i*2)
			np[j] = true;
	}
	int N, C;
	while(scanf("%d %d", &N, &C) > 0){
		printf("%d %d:", N, C);
		int K = upper_bound(prime.begin(), prime.end(), N) - prime.begin();
		C = (K%2 ? C*2-1 : C*2);
		if(C > K) C = K;
		int k = (K-C)/2;
		for(int i = k; i < K-k; ++i)
			printf(" %d", prime[i]);
		puts("\n");
	}
}