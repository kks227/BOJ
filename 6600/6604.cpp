#include <cstdio>
using namespace std;

int main(){
	int N, R[26], C[26];
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		char k;
		int r, c;
		scanf(" %c %d %d", &k, &r, &c);
		R[k-'A'] = r;
		C[k-'A'] = c;
	}
	char E[1000];
	while(scanf("%s", E) > 0){
		int r[1000] = {0}, c[1000] = {0}, t = 0;
		int result = 0;
		bool isError = false;
		for(int i = 0; E[i]; ++i){
			if(E[i] == '(') ++t;
			else if(E[i] == ')'){
				if(r[t-1] == 0) r[t-1] = r[t];
				else{
					if(c[t-1] != r[t]){
						isError = true;
						break;
					}
					result += r[t-1]*c[t-1]*c[t];
				}
				c[t-1] = c[t];
				r[t] = c[t] = 0;
				--t;
			}
			else{
				int k = E[i]-'A';
				if(r[t] == 0) r[t] = R[k];
				else{
					if(c[t] != R[k]){
						isError = true;
						break;
					}
					result += r[t]*c[t]*C[k];
				}
				c[t] = C[k];
			}
		}
		if(isError) puts("error");
		else printf("%d\n", result);
	}
}