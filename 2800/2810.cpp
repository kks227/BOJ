#include <cstdio>
using namespace std;

int main(){
	int result;
	char S[51];
	bool temp = false;
	scanf("%d %s", &result, S);
	for(int i = 0; S[i]; ++i){
		if(S[i] == 'L'){
			--result;
			++i;
			temp = true;
		}
	}
	printf("%d\n", result + temp);
}