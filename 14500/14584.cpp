#include <cstdio>
using namespace std;

int main(){
	int N;
	char S[101], W[20][21];
	scanf("%s %d", S, &N);
	for(int i=0; i<N; i++)
		scanf("%s", W[i]);
	for(int i=0; i<26; i++){
		char T[101] = {0};
		for(int j=0; S[j]; j++)
			T[j] = (S[j]-'a'+i)%26 + 'a';
		for(int j=0; T[j]; j++){
			for(int k=0; k<N; k++){
				bool found = true;
				for(int l=0; W[k][l]; l++){
					if(T[j+l] != W[k][l]){
						found = false;
						break;
					}
				}
				if(found){
					puts(T);
					return 0;
				}
			}
		}
	}
}