#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

int main(){
	int N, A[100000];
	multiset<int> S;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		scanf("%d", A+i);
	sort(A, A+N);
	for(int i = 0; i < N; ++i){
		int val;
		scanf("%d", &val);
		S.insert(val);
	}
	int cnt = 0;
	for(int i = N-1; i >= 0; --i){
		auto iter = S.upper_bound(A[i]);
		if(iter != S.end()){
			S.erase(iter);
			++cnt;
		}
	}
	puts(cnt >= (N+1)/2 ? "YES" : "NO");
}