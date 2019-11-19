#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 26;

char S[MAX+1], T[MAX+1];
int pos;

void restore(int s, int e){
	for(int i = s; i < e; ++i){
		if(S[pos] == T[i]){
			char c = S[pos++];
			restore(s, i);
			restore(i+1, e);
			putchar(c);
			return;
		}
	}
}

int main(){
	while(scanf("%s %s", S, T) > 0){
		pos = 0;
		restore(0, strlen(S));
		puts("");
	}
}