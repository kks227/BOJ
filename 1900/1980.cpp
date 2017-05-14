#include <cstdio>
using namespace std;

int main(){
	int N, M, T;
	scanf("%d %d %d", &N, &M, &T);
	int r1 = -1, r2 = T+1;
	for(int i=0; i*N<=T; i++){
		int j = (T-i*N)/M, k = T-i*N-j*M;
		if(k < r2){
			r2 = k;
            r1 = i+j;
        }
        else if(k == r2 && i+j > r1) r1 = i+j;
	}
	printf("%d %d\n", r1, r2);
}