#include <cstdio>
#include <vector>
#include <set>
using namespace std;

int main(){
	int N, A[100000], p = 0;
	multiset<int> S;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%d", A+i);
		p += A[i];
		S.insert(A[i]);
	}
	int p0 = 0, q0 = 1, q = N-1;

	vector<int> result;
	for(int i = 0; i < N-2; ++i){
		--q;
		p -= A[i];
		S.erase(S.find(A[i]));
		int p1 = p - *S.begin(), q1 = q;
		if(1LL*p1*q0 > 1LL*p0*q1){
			p0 = p1;
			q0 = q1;
			result = vector<int>(1, i+1);
		}
		else if(1LL*p1*q0 == 1LL*p0*q1) result.push_back(i+1);
	}
	for(int i: result)
		printf("%d\n", i);
}