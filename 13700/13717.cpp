#include <cstdio>
using namespace std;
const int MAX = 70;

int main(){
	int N, r0 = 0, r1 = -1, r2 = -1;
	char P[MAX][21];
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		int K, M;
		scanf("%s %d %d", P+i, &K, &M);
		int temp = 0;
		while(K <= M){
			++temp;
			M -= K-2;
		}
		r0 += temp;
		if(temp > r1){
			r1 = temp;
			r2 = i;
		}
	}
	printf("%d\n%s\n", r0, P[r2]);
}