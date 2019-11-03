#include <cstdio>
using namespace std;
const int N = 50;

int main(){
	int score[N], k;
	for(int i = 0; i < N; ++i)
		scanf("%d", score+i);
	scanf("%d", &k);
	for(int i = 0; i < N; ++i){
		if(score[i] == k){
			if(i < 5) puts("A+");
			else if(i < 15) puts("A0");
			else if(i < 30) puts("B+");
			else if(i < 35) puts("B0");
			else if(i < 45) puts("C+");
			else if(i < 48) puts("C0");
			else puts("F");
			break;
		}
	}
}