#include <cstdio>
using namespace std;

int main(){
	int N, result = 0, bonus = 0;
	scanf("%d\n", &N);
	for(int i = 1; i <= N; ++i){
		char c = getchar();
		if(c == 'O') result += i + bonus++;
		else bonus = 0;
	}
	printf("%d\n", result);
}