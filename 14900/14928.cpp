#include <cstdio>
using namespace std;
const int MOD = 20000303;

int main(){
	int result = 0;
	while(1){
		char c = getchar();
		if(c < 0 || c == '\n') break;
		result = (result*10%MOD + c-'0') % MOD;
	}
	printf("%d\n", result);
}