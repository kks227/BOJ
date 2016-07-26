#include <cstdio>
#include <vector>
using namespace std;

// A >= B
vector<int> operator +(vector<int> &A, vector<int> &B){
	bool carry = false;
	vector<int> result(A.size(), 0);
	for(int i=0; i<A.size(); i++){
		result[i] = A[i] + (i<B.size()?B[i]:0) + carry;
		if(result[i] >= 10){
			carry = true;
			result[i] -= 10;
		}
		else carry = false;
	}
	if(carry) result.push_back(1);
	return result;
}

int main(){
	int N;
	scanf("%d", &N);
	if(N<2){
		printf("%d\n", N);
		return 0;
	}
	vector<int> A(1, 0), B(1, 1), C;
	for(int i=2; i<=N; i++){
		C = B+A;
		A = B;
		B = C;
	}
	for(int i=B.size()-1; i>=0; i--)
		printf("%d", B[i]);
}