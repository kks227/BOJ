#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 250000;

int main(){
	int N, result = 1, temp = 1;
	char S[MAX+1];
	scanf("%d %s", &N, S);
	for(int i = 1; i < N; ++i){
		if(S[i-1] == S[i] || S[i-1] == 'V' || S[i] == 'V') temp = 1;
		else ++temp;
		result = max(temp, result);
	}
	printf("%d\n", result);
}