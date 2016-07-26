#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const long long MAX = 10000000;

int main(){
	vector<bool> np(MAX, false);
	vector<long long> result;
	long long A, B;
	scanf("%lld %lld", &A, &B);
	for(long long i=4; i<MAX*MAX; i*=2)
		result.push_back(i);
	for(int i=3; i<MAX; i+=2){
		if(np[i]) continue;
		for(long long j=1LL*i*i; ;){
			result.push_back(j);
			if(j >= MAX*MAX/i) break;
			j *= i;
		}
		if(1LL*i*i >= MAX) continue;
		for(int j=i*i; j<MAX; j+=i*2)
			np[j] = true;
	}
	sort(result.begin(), result.end());
	printf("%d\n", upper_bound(result.begin(), result.end(), B)-lower_bound(result.begin(), result.end(), A));
}