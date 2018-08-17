#include <cstdio>
#include <vector>
using namespace std;
const int MAX_P = 10000000;

int main(){
	bool notP[MAX_P+1] = {true, true,};
	vector<int> prime(1, 2);
	for(int i=3; i<=MAX_P; i+=2){
		if(notP[i]) continue;
		prime.push_back(i);
		for(long long j=1LL*i*i; j<=MAX_P; j+=2*i)
			notP[j] = true;
	}
	int K;
	scanf("%d", &K);
	printf("%d\n", prime[K-1]);
}