#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

struct BigInt{
	string val;
	BigInt(){ val = ""; }
	BigInt(int n){
		val = "";
		do{
			val.push_back(n%10+'0');
			n /= 10;
		}while(n);
	}
	void print(){
		for(int i=val.size()-1; i>=0; i--) putchar(val[i]);
		puts("");
	}
};

BigInt operator +(const BigInt &A, const BigInt &B){
	BigInt C;
	bool carry = false;
	for(int i=0; i<max(A.val.size(), B.val.size()); i++){
		int temp = carry;
		if(i < A.val.size()) temp += A.val[i]-'0';
		if(i < B.val.size()) temp += B.val[i]-'0';
		carry = (temp >= 10);
		temp %= 10;
		C.val.push_back(temp+'0');
	}
	if(carry) C.val.push_back('1');
	return C;
}



int N;
bool visited[10001][2];
BigInt dp[10001][2];

BigInt matching(int n, bool first){
	if(visited[n][first]) return dp[n][first];
	visited[n][first] = true;

	BigInt &ret = dp[n][first];
	if(n == 0) return ret = BigInt(1);
	if(n == 1) return ret = BigInt(first ? 1 : 2);
	return ret = matching(n-1, first) + matching(n-2, first);
}

int main(){
	while(scanf("%d", &N) > 0){
		BigInt result = matching(N-1, false) + matching(N-2, true);
		result.print();
	}
}