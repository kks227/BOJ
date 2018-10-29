#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;

int main(){
	int T;
	scanf("%d\n", &T);
	for(int t = 1; t <= T; ++t){
		char S[500];
		gets_s(S);
		int L = strlen(S);
		double val[3] = {-1, -1, -1}; // P, U, I
		for(int i = 0; S[i]; ++i){
			if(S[i] == '='){
				int k = (S[i-1] == 'P' ? 0 : (S[i-1] == 'U' ? 1 : 2));
				int s = ++i;
				for(++i; isdigit(S[i]) || S[i] == '.'; ++i);
				char buffer[500] = {'\0'};
				strncpy(buffer, S+s, i-s);
				sscanf(buffer, "%lf", val+k);
				if(S[i] == 'm') val[k] *= 0.001;
				else if(S[i] == 'k') val[k] *= 1000;
				else if(S[i] == 'M') val[k] *= 1000000;
				++i;
			}
		}
		printf("Problem #%d\n", t);
		if(val[0] < 0)
			printf("P=%.2lfW\n", val[1]*val[2]);
		else if(val[1] < 0)
			printf("U=%.2lfV\n", val[0]/val[2]);
		else
			printf("I=%.2lfA\n", val[0]/val[1]);
		puts("");
	}
}