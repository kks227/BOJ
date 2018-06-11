#include <cstdio>
#include <queue>
using namespace std;

int main(){
	int N, cnt = 0;
	queue<int> Q;
	scanf("%d", &N);
	while(1){
		int D;
		scanf("%d", &D);
		if(D < 0) break;
		else if(D == 0){
			if(cnt > 0){
				Q.pop();
				cnt--;
			}
		}
		else{
			if(cnt < N){
				Q.push(D);
				cnt++;
			}
		}
	}

	if(cnt == 0) puts("empty");
	else{
		while(!Q.empty()){
			printf("%d ", Q.front());
			Q.pop();
		}
	}
}