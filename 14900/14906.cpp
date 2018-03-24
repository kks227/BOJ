#include <cstdio>
using namespace std;

int N;
char S[61];

int slump(int pos){
	if(S[pos] != 'D' && S[pos] != 'E') return -1;
	if(S[++pos] != 'F') return -1;
	while(S[++pos] == 'F');
	if(S[pos] == 'G') return pos+1;
	return slump(pos);
}

int slimp(int pos){
	if(S[pos] != 'A') return -1;
	if(S[++pos] == 'H') return pos+1;
	pos = (S[pos] == 'B' ? slimp(pos+1) : slump(pos));
	if(pos < 0) return -1;
	if(S[pos] == 'C') return pos+1;
	return -1;
}

int slurpy(int pos){
	pos = slimp(pos);
	if(pos < 0) return -1;
	pos = slump(pos);
	if(pos < 0) return -1;
	return pos;
}

int main(){
	scanf("%d", &N);
	puts("SLURPYS OUTPUT");
	for(int i=0; i<N; i++){
		scanf("%s", S);
		puts(slurpy(0) >= 0 ? "YES" : "NO");
	}
	puts("END OF OUTPUT");
}