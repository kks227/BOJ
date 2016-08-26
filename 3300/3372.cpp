#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct BigInt{
	vector<char> val;
	BigInt(): BigInt(0){}
	BigInt(int n){
		do{
			val.push_back(n%10);
			n /= 10;
		}while(n);
	}
	BigInt operator +(const BigInt& O)const{
		BigInt result;
		result.val.resize(max(val.size(), O.val.size()));
		bool carry = 0;
		for(int i=0; i<result.val.size(); i++){
			int temp = carry;
			if(i < val.size()) temp += val[i];
			if(i < O.val.size()) temp += O.val[i];
			carry = (temp >= 10);
			temp %= 10;
			result.val[i] = temp;
		}
		if(carry) result.val.push_back(1);
		return result;
	}
	void print()const{
		for(int i=val.size()-1; i>=0; i--)
			printf("%d", val[i]);
	}
};

int N, map[100][100];
bool visited[100][100];
BigInt dp[100][100];

BigInt jump(int r, int c){
	BigInt &ret = dp[r][c];
	if(visited[r][c]) return ret;
	visited[r][c] = true;
	if(r == N-1 && c == N-1) return ret = BigInt(1);

	if(r+map[r][c] < N) ret = ret + jump(r+map[r][c], c);
	if(c+map[r][c] < N) ret = ret + jump(r, c+map[r][c]);
	return ret;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			scanf("%d", &map[i][j]);
	jump(0, 0).print();
}