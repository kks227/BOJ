#include <cstdio>
using namespace std;

int main(){
	int score[2] = {0};
	for(int i = 0; i < 2; ++i){
		for(int j = 3; j > 0; --j){
			int val;
			scanf("%d", &val);
			score[i] += val * j;
		}
	}
	if(score[0] > score[1]) putchar('A');
	else if(score[0] < score[1]) putchar('B');
	else putchar('T');
}