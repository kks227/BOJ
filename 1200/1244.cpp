#include <cstdio>
using namespace std;

int main(){
	int N, M;
	bool flag[100];
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		int val;
		scanf("%d", &val);
		flag[i] = val;
	}
	scanf("%d", &M);
	for(int i = 0; i < M; ++i){
		int gender, k;
		scanf("%d %d", &gender, &k);
		if(gender == 1){
			for(int j = k-1; j < N; j += k)
				flag[j] = !flag[j];
		}
		else{
			flag[k-1] = !flag[k-1];
			for(int j1 = k-2, j2 = k; j1 >= 0 && j2 < N && flag[j1] == flag[j2]; --j1, ++j2){
				flag[j1] = !flag[j1];
				flag[j2] = !flag[j2];
			}
		}
	}
	for(int i = 0; i < N; ++i){
		printf("%d", flag[i]);
		if(i%20 == 19 || i == N-1) puts("");
		else putchar(' ');
	}
}