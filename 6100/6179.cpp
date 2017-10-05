#include <cstdio>
using namespace std;

inline int p2(int n){ return n*n; }

int main(){
	int N, x[1080], y[1080], r[1080], curr;
	bool visited[1080] = {0};
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d %d %d", x+i, y+i, r+i);
		if(x[i] == 0 && y[i] == 0) curr = i;
	}
	for(int i=0; i<N-1; i++){
		visited[curr] = true;
		for(int j=0; j<N; j++){
			if(p2(x[curr]-x[j])+p2(y[curr]-y[j]) == p2(r[curr]+r[j]) && !visited[j]){
				curr = j;
				break;
			}
		}
	}
	printf("%d %d\n", x[curr], y[curr]);
}