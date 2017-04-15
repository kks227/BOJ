#include <cstdio>
#include <cmath>
using namespace std;

int N;

void dfs(int pos, int curr){
	if(pos == N){
		printf("%d\n", curr);
		return;
	}

	for(int d=1; d<10; d+=2){
		int next = curr*10 + (pos==0 && d==1 ? 2 : d);
		bool prime = true;
		for(int i=2; i<=round(sqrt(next)); i++){
			if(next%i == 0){
				prime = false;
				break;
			}
		}
		if(prime) dfs(pos+1, next);
	}
}

int main(){
	scanf("%d", &N);
	dfs(0, 0);
}