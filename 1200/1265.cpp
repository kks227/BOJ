#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
const int PIVOT = 6;

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



int N, K;
bool visited[101][64][128];
BigInt dp[101][64][128];

// late의 i번 비트: pos-i-1을 아직 안썼다
// early의 i번 비트: pos+i를 미리 썼다
BigInt sequence(int pos, int late, int early){
	BigInt &ret = dp[pos][late][early];
	if(visited[pos][late][early]) return ret;
	visited[pos][late][early] = true;

	if(pos == N) return ret = !late;
	if(late & 1<<K-1)
		return ret = sequence(pos+1, (late-(1<<K-1)<<1) + !(early&1), early>>1);

	ret = 0;
	for(int i=0; i<K; i++){
		if(pos-i-1 < 0) break;
		if(late & 1<<i)
			ret = ret + sequence(pos+1, (late-(1<<i)<<1) + !(early&1), early>>1);
	}
	if((early & 1) == 0)
		ret = ret + sequence(pos+1, late<<1, early>>1);
	for(int i=1; i<=K; i++){
		if(pos+i >= N) break;
		if((early & 1<<i) == 0)
			ret = ret + sequence(pos+1, (late<<1) + !(early&1), early+(1<<i)>>1);
	}
	return ret;
}

int main(){
	scanf("%d %d", &N, &K);
	sequence(0, 0, 0).print();
}