#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	char S[1000001], R[1000001], E[37];
	scanf("%s %s", S, E);
	int pos = 0, Elen = strlen(E);
	for(int i=0; S[i]; i++){
		R[pos++] = S[i];
		if(pos < Elen) continue;

		bool ex = true;
		for(int j=0; j<Elen; j++){
			if(R[pos-Elen+j] != E[j]){
				ex = false;
				break;
			}
		}
		if(ex) pos -= Elen;
	}

	if(pos == 0) puts("FRULA");
	else for(int i=0; i<pos; i++) putchar(R[i]);
}