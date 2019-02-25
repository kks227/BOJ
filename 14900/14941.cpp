#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_P = 100020;

int main(){
	vector<int> prime(1, 2), pSum[2];
	bool np[MAX_P] = {false,};
	for(int i = 3; i < MAX_P; i += 2){
		if(np[i]) continue;
		prime.push_back(i);
		for(long long j = 1LL*i*i; j < MAX_P; j += i*2)
			np[j] = true;
	}
	pSum[0].push_back(0);
	pSum[1].push_back(0);
	for(int i = 0; i < prime.size(); ++i){
		pSum[0].push_back(pSum[0][i] + prime[i]*(i%2?-1:3));
		pSum[1].push_back(pSum[1][i] + prime[i]*(i%2?3:-1));
	}

	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		int a, b;
		scanf("%d %d", &a, &b);
		int s = lower_bound(prime.begin(), prime.end(), a) - prime.begin();
		int e = upper_bound(prime.begin(), prime.end(), b) - prime.begin();
		if(s%2 == 0) printf("%d\n", pSum[0][e] - pSum[0][s]);
		else printf("%d\n", pSum[1][e] - pSum[1][s]);
	}
}