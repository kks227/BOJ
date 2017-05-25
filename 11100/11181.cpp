#include <cstdio>
using namespace std;

int main(){
	int M;
	scanf("%d", &M);
	if(M-- == 1){
		puts("1");
		return 0;
	}
	for(int i=1; ; i++){
		for(int j=0; j<2; j++){
			int K = (1<<i-1)*(j+1);
			if(M <= K){
				int k = M-1, L = i;
				bool b[64] = {1,};
				if(j){
					b[L++] = k%2;
					k /= 2;
				}
				for(int l=i-1; l>0; l--){
					b[l] = k%2;
					k /= 2;
				}
				for(int l=i-1; l>=0; l--, L++)
					b[L] = b[l];
				long long result = 0;
				for(int l=0; l<L; l++)
					result = result*2 + b[l];
				printf("%lld\n", result);
				return 0;
			}
			M -= K;
		}
	}
}