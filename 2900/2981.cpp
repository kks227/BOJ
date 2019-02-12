#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

int main(){
	int N, A[100];
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		scanf("%d", A+i);
	sort(A, A+N);
	int gcd = A[1]-A[0];
	for(int i = 2; i < N; ++i){
		int p = gcd, q = A[i]-A[i-1], r;
		while(q){
			r = p % q;
			p = q;
			q = r;
		}
		gcd = p;
	}
	set<int> result;
	for(int i = 2; i*i <= gcd; ++i){
		if(gcd%i == 0){
			result.insert(i);
			result.insert(gcd/i);
		}
	}
	result.insert(gcd);
	for(int i: result)
		printf("%d ", i);
}