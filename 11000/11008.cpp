#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		char S[10001], P[101];
		scanf("%s %s", S, P);
		int result = 0, L = strlen(P);
		for(int i = 0; S[i]; ++result){
			bool flag = true;
			for(int j = 0; j < L; ++j){
				if(!S[i+j] || S[i+j] != P[j]){
					flag = false;
					break;
				}
			}
			i += (flag ? L : 1);
		}
		printf("%d\n", result);
	}
}