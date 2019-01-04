#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int main(){
	int N, A[1000], result = INF;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		scanf("%d", A+i);
	for(int i = 0; i < N; ++i){
		int temp = 0;
		set<int> S;
		for(int j = 0; j < N; ++j)
			S.insert(j);
		for(int j = 0; j < N; ++j){
			int pos = (i+j) % N;
			for(int k = 0; k < A[pos]; ++k){
				auto iter = S.lower_bound(pos);
				int d;
				if(iter != S.end()) d = *iter - pos;
				else{
					iter = S.lower_bound(0);
					d = N - pos + *iter;
				}
				temp += d*d;
				S.erase(iter);
			}
		}
		result = min(temp, result);
	}
	printf("%d\n", result);
}