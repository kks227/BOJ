#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	while(1){
		char N[6];
		scanf("%s", N);
		if(N[0] == '0') break;

		int L = strlen(N);
		bool result = true;
		for(int i=0; i<L; i++){
			if(N[i] != N[L-i-1]){
				result = false;
				break;
			}
		}
		puts(result ? "yes" : "no");
	}
}