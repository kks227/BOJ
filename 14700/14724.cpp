#include <cstdio>
using namespace std;

int main(){
	char *club[] = {"PROBRAIN", "GROW", "ARGOS", "ADMIN", "ANT", "MOTION", "SPG", "COMON", "ALMIGHTY"};
	int N, result = -1, val = -1;
	scanf("%d", &N);
	for(int i=0; i<9; i++){
		for(int j=0; j<N; j++){
			int score;
			scanf("%d", &score);
			if(score > val){
				val = score;
				result = i;
			}
		}
	}
	puts(club[result]);
}