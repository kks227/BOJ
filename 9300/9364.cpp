#include <cstdio>
#include <cctype>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t){
		int x;
		char E[1000] = {'\0'};
		scanf("%d %s", &x, E);

		long long result = 0, pow[32] = {1, x,};
		for(int i = 2; i < 32; ++i)
			pow[i] = pow[i-1] * x;
		for(int i = 0; E[i]; ){
			int sign = 1, e = 0, c = 0;

			if(!isdigit(E[i]) && E[i] != 'X'){
				if(E[i++] == '-') sign = -1;
			}

			if(isdigit(E[i])){
				while(isdigit(E[i]))
					c = c*10 + E[i++]-'0';
			}
			else c = 1;

			if(E[i] == 'X'){
				if(E[++i] == '^'){
					for(++i; isdigit(E[i]); ++i)
						e = e*10 + E[i]-'0';
				}
				else e = 1;
			}

			result += sign * c * pow[e];
		}
		printf("Case #%d: %lld\n", t, result);
	}
}