#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
	char S[11];
	scanf("%s", S);
	int L = strlen(S), result = 0;
	sort(S, S+L);
	do{
		bool success = true;
		for(int i=0; i<L-1; i++){
			if(S[i] == S[i+1]){
				success = false;
				break;
			}
		}
		if(success) result++;
	}while(next_permutation(S, S+L));
	printf("%d\n", result);
}