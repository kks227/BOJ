#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	for(int t=1; ; t++){
		char N[101];
		scanf("%s", N);
		if(N[0] == '0') break;

		while(1){
			int L = strlen(N);
			if(L%2) break;
			bool bflag = false;
			for(int i=3; i<L; i+=2){
				if(N[i] == N[i-2]){
					bflag = true;
					break;
				}
			}
			if(bflag) break;

			char M[101] = "";
			for(int i=0, j=0; i<L; i+=2){
				for(int k=0; k<N[i]-'0'; k++)
					M[j++] = N[i+1];
			}
			if(!strcmp(N, M)) break;
			strcpy(N, M);
		}
		printf("Test %d: %s\n", t, N);
	}
}