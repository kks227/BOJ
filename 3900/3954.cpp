#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;
const int MAX = 4096;
const int MAX_M = 100000;
const int MOD_M = 256;
const int IS_LIMIT = 50000000;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int ML, SL, IL, lp[MAX] = {0}; // left-right pair of each loop
		unsigned char M[MAX_M] = {0}, S[MAX+1], I[MAX+1];
		scanf("%d %d %d %s %s", &ML, &SL, &IL, S, I);
		I[IL] = MOD_M - 1; // EOF

		int mp = 0, sp = 0, ip = 0, scnt = 0;
		stack<int> loop;
		for(int i=0; i<SL; i++){
			if(S[i] == '[') loop.push(i);
			else if(S[i] == ']'){
				lp[i] = loop.top();
				lp[loop.top()] = i;
				loop.pop();
			}
		}

		bool infiniteLoop = false;
		int lpos = SL + 1;
		while(sp < SL && !infiniteLoop){
			switch(S[sp]){
			case '-':
				M[mp] = (M[mp] + MOD_M - 1) % MOD_M;
				sp++;
				break;

			case '+':
				M[mp] = (M[mp] + 1) % MOD_M;
				sp++;
				break;

			case '<':
				mp = (mp + ML - 1) % ML;
				sp++;
				break;

			case '>':
				mp = (mp + 1) % ML;
				sp++;
				break;

			case '[':
				if(scnt >= IS_LIMIT*2){
					infiniteLoop = true;
					break;
				}
				else if(scnt >= IS_LIMIT) lpos = min(sp, lpos);

				if(M[mp]) sp++;
				else sp = lp[sp] + 1;
				break;

			case ']':

				if(M[mp]) sp = lp[sp];
				else sp++;
				break;

			case ',':
				M[mp] = I[ip];
				if(ip < IL) ip++;
				sp++;
				break;

			default: // do nothing for output operations
				sp++;
			}

			scnt++;
		}
		if(infiniteLoop) printf("Loops %d %d\n", lpos, lp[lpos]);
		else puts("Terminates");
	}
}