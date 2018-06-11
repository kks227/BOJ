#include <cstdio>
using namespace std;

int main(){
	char result[9] = "abbcdddc";
	int N;
	scanf("%d", &N);
	printf("%c\n", result[N-1]);
}