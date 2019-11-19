#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_M = 1000;
const int MAX = MAX_M * MAX_M;

inline int cntDigits(int n){
	int result = 0;
	do{
		++result;
		n /= 10;
	}while(n > 0);
	return result;
}

inline int getKthDigit(int n, int k){
	vector<int> v;
	do{
		v.push_back(n % 10);
		n /= 10;
	}while(n > 0);
	return v[v.size()-k-1];
}

int main(){
	int Q, M, val[MAX], d[MAX], pSum[MAX+1] = {0,}, X = 0, Y = 0, Z = 0, pos[MAX];
	scanf("%d %d", &Q, &M);
	fill(pos, pos + MAX, -1);
	for(int i = 0, j = 1; ; ++Z){
		if(pos[i*M + j] != -1){
			X = pos[i*M + j];
			Y = Z - X;
			break;
		}
		pos[i*M + j] = Z;
		val[Z] = j;
		d[Z] = cntDigits(j);
		pSum[Z+1] = pSum[Z] + d[Z];
		int k = (i + j) % M;
		i = j;
		j = k;
	}
	for(int i = 0; i < Q; ++i){
		long long N;
		scanf("%lld", &N);
		--N;
		if(N < pSum[X]){
			int k = upper_bound(pSum, pSum+X, N) - pSum - 1;
			printf("%d\n", getKthDigit(val[k], N-pSum[k]));
		}
		else{
			N -= pSum[X];
			N %= (pSum[Z] - pSum[X]);
			int k = upper_bound(pSum+X, pSum+Z, N) - pSum - 1;
			printf("%d\n", getKthDigit(val[k], N-pSum[k]));
		}
	}
}