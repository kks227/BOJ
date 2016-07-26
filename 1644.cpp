#include <cstdio>
#include <vector>
using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	bool np[4000000] = {0};
	vector<int> prime(1, 2);
	for(int i=3; i<4000000; i+=2){
		if(np[i]) continue;
		prime.push_back(i);
		if(1LL*i*i >= 4000000) continue;
		for(int j=i*i; j<4000000; j+=i*2)
			np[j] = true;
	}
	int result = 0, sum = 0, lo = 0, hi = 0;
	while(1){
		if(sum >= N) sum -= prime[lo++];
		else if(hi == prime.size()) break;
		else sum += prime[hi++];
		if(sum == N) result++;
	}
	printf("%d\n", result);
}