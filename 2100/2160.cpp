#include <cstdio>
using namespace std;

int main(){
	int N, val = 36, r1, r2;
	char P[50][5][7];
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		for(int j=0; j<5; j++){
			getchar();
			for(int k=0; k<7; k++)
				P[i][j][k] = getchar();
		}
	}
	for(int i=0; i<N-1; i++){
		for(int j=i+1; j<N; j++){
			int cnt = 0;
			for(int k=0; k<5; k++)
				for(int l=0; l<7; l++)
					cnt += (P[i][k][l] != P[j][k][l]);
			if(cnt < val){
				val = cnt;
				r1 = i+1;
				r2 = j+1;
			}
		}
	}
	printf("%d %d\n", r1, r2);
}