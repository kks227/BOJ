#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 200000;

int main(){
	char S[2][MAX+1], T[MAX+1];
	scanf("%s %s %s", S[0], S[1], T);
	int N[2] = {strlen(S[0]), strlen(S[1])}, M = strlen(T), p[MAX] = {0};
	for(int i = 1, j = 0; i < M; ++i){
		while(j > 0 && T[i] != T[j]) j = p[j-1];
		if(T[i] == T[j]) p[i] = ++j;
	}

	bool result = true;
	for(int k = 0; k < 2; ++k){
		bool flag = false;
		for(int i = 0, j = 0; i < N[k]; ++i){
			while(j > 0 && S[k][i] != T[j]) j = p[j-1];
			if(S[k][i] == T[j]){
				if(j == M-1){
					flag = true;
					break;
				}
				++j;
			}
		}
		if(!flag) result = false;
	}
	puts(result ? "YES" : "NO");
}