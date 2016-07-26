#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef vector<int> BigInt;
typedef map<int, BigInt> M;

const BigInt operator +(const BigInt &A, const BigInt &B){
	BigInt result;
	bool carry = false;
	int loops = max(A.size(), B.size());
	for(int i=0; i<loops; i++){
		result.push_back((i<A.size()?A[i]:0) + (i<B.size()?B[i]:0) + carry);
		if(result[i] >= 10){
			carry = true;
			result[i] -= 10;
		}
		else carry = false;
	}
	if(carry) result.push_back(1);
	return result;
}

int N;
M cache;

BigInt tiling(int pos){
	if(pos == N) return BigInt(1, 1);
	if(pos == N-1) return BigInt(1, 1);
	if(pos == N-2) return BigInt(1, 3);
	M::iterator iter = cache.find(pos);
	if(iter != cache.end()) return iter->second;
	return cache[pos] = tiling(pos+1) + tiling(pos+2) + tiling(pos+2);
}

void printBigInt(const BigInt &N){
	for(int i=N.size()-1; i>=0; i--)
		printf("%d", N[i]);
}

int main(){
	while(scanf("%d", &N) == 1){
		cache.clear();
		printBigInt(tiling(0));
		puts("");
	}
}