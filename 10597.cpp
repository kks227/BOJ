#include <cstdio>
using namespace std;
const int MAX = 50;

char S[101];
int N, result[MAX];
bool success, used[MAX];

inline int digit(int n){ return (n>=10 ? 2 : 1); }

bool backtrack(int k, int pos){
	if(success) return true;
	if(k == N){
		success = true;
		for(int i=0; i<N; i++)
			printf("%d ", result[i]);
		return true;
	}
	// one digit
	int d1 = S[pos]-'0';
	if(d1>0 && !used[d1-1]){
		used[d1-1] = true;
		result[k] = d1;
		if(backtrack(k+1, pos+1)) return true;
		used[d1-1] = false;
	}
	// two digits
	if(S[pos+1]){
		int n = d1*10 + S[pos+1]-'0';
		if(n>0 && n<=N && !used[n-1]){
			used[n-1] = true;
			result[k] = n;
			if(backtrack(k+1, pos+2)) return true;
			used[n-1] = false;
		}
	}
	return false;
}

int main(){
	scanf("%s", S);
	for(int pos=0; S[pos];){
		N++;
		pos += digit(N);
	}
	backtrack(0, 0);
}