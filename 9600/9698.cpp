#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t){
		int H, M;
		scanf("%d %d", &H, &M);
		M -= 45;
		if(M < 0){
			if(--H < 0) H += 24;
			M += 60;
		}
		printf("Case #%d: %d %d\n", t, H, M);
	}
}