#include <cstdio>
using namespace std;

int main(){
	int N, M;
	char S[101];
	scanf("%d %d %s", &N, &M, S);
	for(int i=0; i<M; i++){
		char T[1001];
		scanf("%s", T);
		bool result = true;
		for(int i=0, j=0; S[i]; j++){
			if(!T[j]){
				result = false;
				break;
			}
			if(S[i] == T[j]) i++;
		}
		puts(result ? "true" : "false");
	}
}