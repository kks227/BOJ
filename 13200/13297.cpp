#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		char S[102];
		scanf("%s", S);
		printf("%d\n", strlen(S));
	}
}