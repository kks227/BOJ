#include <cstdio>
using namespace std;

int N, op[8];
char o2c[3] = {' ', '+', '-'};

void dfs(int n){
	if(n == N-1){
		int sum = 0, val = 1, sign = 1;
		for(int i=0; i<N-1; i++){
			if(op[i] == 0) val = val*10 + i+2;
			else{
				sum += val * sign;
				val = i+2;
				sign = (op[i] == 1 ? 1 : -1);
			}
		}
		sum += val * sign;
		if(sum == 0){
			for(int i=0; ; i++){
				printf("%d", i+1);
				if(i == N-1){
					puts("");
					break;
				}
				putchar(o2c[op[i]]);
			}
		}
		return;
	}
	for(int i=0; i<3; i++){
		op[n] = i;
		dfs(n+1);
	}
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		scanf("%d", &N);
		dfs(0);
		puts("");
	}
}