#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int P, M, result = 0;
		scanf("%d %d", &P, &M);
		bool filled[500] = {0};
		for(int i=0; i<P; i++){
			int seat;
			scanf("%d", &seat);
			seat--;
			if(!filled[seat]) filled[seat] = true;
			else result++;
		}
		printf("%d\n", result);
	}
}