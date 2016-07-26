#include <cstdio>
using namespace std;

int main(){
	int N[6], result = 0;
	for(int i=0; i<6; i++)
		scanf("%d", N+i);
	result = N[5] + N[4] + N[3];
	N[0] -= N[4]*11;
	N[1] -= N[3]*5;
	if(N[1] < 0){
		N[0] += N[1]*4;
		N[1] = 0;
	}
	result += N[2]/4;
	N[2] %= 4;
	if(N[2]){
		N[1] -= 7 - N[2]*2;
		N[0] -= 36 - N[2]*9 - (7 - N[2]*2)*4;
		result++;
	}
	if(N[1] < 0) N[1] = 0;
	result += N[1]/9;
	N[1] %= 9;
	if(N[1]){
		N[0] -= (9 - N[1])*4;
		result++;
	}
	if(N[0] < 0) N[0] = 0;
	result += N[0]/36 + (N[0]%36 > 0);
	printf("%d\n", result);
}