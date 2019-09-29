#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	int N;
	bool r1 = true, r2 = true;
	char S[20][13];
	scanf("%d %s", &N, S[0]);
	for(int i = 1; i < N; ++i){
		scanf("%s", S[i]);
		int temp = strcmp(S[i-1], S[i]);
		if(temp < 0) r2 = false;
		else if(temp > 0) r1 = false;
	}
	if(r1) puts("INCREASING");
	else if(r2) puts("DECREASING");
	else puts("NEITHER");
}