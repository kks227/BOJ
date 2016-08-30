#include <cstdio>
using namespace std;

int main(){
	int e, f, c, result = 0;
	scanf("%d %d %d", &e, &f, &c);
	e += f;
	while(e >= c){
		result += e/c;
		e = e/c + e%c;
	}
	printf("%d\n", result);
}