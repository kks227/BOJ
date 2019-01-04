#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const int MAX = 100000;

int main(){
	int N, A[MAX], s = -1;
	long long sVal = 0, result = 0;
	scanf("%d", &N);
	set<int> S;
	for(int i = 0; i < N; ++i){
		scanf("%d", A+i);
		sVal = max(sVal-1+A[i], 0LL);
		S.insert(i);
	}
	for(int i = 0; ; ++i){
		if(sVal == 0){
			s = i;
			break;
		}
		sVal = max(sVal-1+A[i], 0LL);
	}

	for(int i = 0; i < N; ++i){
		int pos = (s+i) % N;
		for(int j = 0; j < A[pos]; ++j){
			auto iter = S.lower_bound(pos);
			long long d;
			if(iter != S.end()) d = *iter - pos;
			else{
				iter = S.lower_bound(0);
				d = N - pos + *iter;
			}
			result += d*d;
			S.erase(iter);
		}
	}
	printf("%lld\n", result);
}