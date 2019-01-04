#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

int main(){
	int N, A[50000], result = 0;
	bool flag[100000] = {false,};
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%d", A+i);
		flag[--A[i]] = true;
	}
	set<int> S;
	for(int i = 0; i < 2*N; ++i)
		if(!flag[i]) S.insert(i);
	for(int i = 0; i < N; ++i){
		auto iter = S.upper_bound(A[i]);
		if(iter == S.end()) S.erase(S.begin());
		else{
			++result;
			S.erase(iter);
		}
	}
	printf("%d\n", result);
}