#include <cstdio>
using namespace std;

int main(){
	int R, C, ZR, ZC;
	char S[250][251] = {0};
	scanf("%d %d %d %d", &R, &C, &ZR, &ZC);
	for(int i=0; i<R; i++){
		getchar();
		for(int j=0; j<C; j++){
			char c = getchar();
			for(int ii=i*ZR; ii<(i+1)*ZR; ii++)
				for(int jj=j*ZC; jj<(j+1)*ZC; jj++)
					S[ii][jj] = c;
		}
	}
	for(int i=0; i<R*ZR; i++)
		puts(S[i]);
}