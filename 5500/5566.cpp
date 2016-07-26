#include <cstdio>
using namespace std;

int main(){
	int N, M, cell[1000], pos = 0;
	bool success = false;
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++)
		scanf("%d", cell+i);
	for(int i=1; i<=M; i++){
		int dice;
		scanf("%d", &dice);
		if(!success){
			pos += dice;
			if(pos >= N-1){
				success = true;
				printf("%d\n", i);
				continue;
			}
			pos += cell[pos];
			if(pos >= N-1){
				success = true;
				printf("%d\n", i);
			}
		}
	}
}