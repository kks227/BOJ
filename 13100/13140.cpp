#include <cstdio>
using namespace std;

int pos, k[7], N;
bool used[10];

bool hw(){
	if(pos == 7){
		if((k[0]+k[4])*10000 + k[1]*1000 + k[2]*120 + k[3]*1001 + k[5]*100 + k[6] == N){
			printf("  %d%d%d%d%d\n", k[0], k[1], k[2], k[2], k[3]);
			printf("+ %d%d%d%d%d\n", k[4], k[3], k[5], k[2], k[6]);
			printf("-------\n");
			printf("%7d\n", N);
			return true;
		}
		return false;
	}
	for(int i=0; i<10; i++){
		if(used[i]) continue;
		if(i == 0 && (pos == 0 || pos == 4)) continue;
		used[i] = true;
		k[pos++] = i;
		if(hw()) return true;
		pos--;
		used[i] = false;
	}
	return false;
}

int main(){
	scanf("%d", &N);
	if(!hw()) puts("No Answer");
}