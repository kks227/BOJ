#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 1000000;

int main(){
	int pos = 0, N;
	char S[MAX+1];
	scanf("%s %d", S, &N);
	for(int i = 0; i < N; ++i){
		char T[10], V[17] = {0,};
		scanf("%s", T);
		int k;
		long long result;
		if(T[0] == 'c') k = 2;
		else if(T[0] == 'i') k = 8;
		else k = 16;
		strncpy(V, S+pos, k);
		pos += k;
		sscanf(V, "%llx", &result);
		printf("%lld ", result);
	}
}