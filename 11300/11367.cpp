#include <cstdio>
using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		char name[11];
		int score;
		scanf("%s %d", name, &score);
		printf("%s ", name);
		if(score >= 97) puts("A+");
		else if(score >= 90) puts("A");
		else if(score >= 87) puts("B+");
		else if(score >= 80) puts("B");
		else if(score >= 77) puts("C+");
		else if(score >= 70) puts("C");
		else if(score >= 67) puts("D+");
		else if(score >= 60) puts("D");
		else puts("F");
	}
}