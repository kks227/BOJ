#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		printf("%d %d %d %s\n", a, b, c, (a+b+c == 180 ? "Seems OK" : "Check"));
	}
}