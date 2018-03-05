#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N, L[100];
		char S[100][10001];
		scanf("%d", &N);
		for(int i=0; i<N; i++){
			scanf("%s", S[i]);
			L[i] = strlen(S[i]);
		}
		bool success = false;
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				if(i == j) continue;

				char T[20001] = {0};
				strcpy(T, S[i]);
				strcpy(T+L[i], S[j]);
				bool same = true;
				for(int a=0, b=L[i]+L[j]-1; a<=b; a++, b--){
					if(T[a] != T[b]){
						same = false;
						break;
					}
				}
				if(same){
					puts(T);
					success = true;
					break;
				}
			}
			if(success) break;
		}
		if(!success) puts("0");
	}
}