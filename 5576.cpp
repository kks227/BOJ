#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	for(int k=0; k<2; k++){
		int score[10];
		for(int i=0; i<10; i++)
			scanf("%d", score+i);
		sort(score, score+10);
		printf("%d\n", score[7]+score[8]+score[9]);
	}
}