#include <cstdio>
using namespace std;
const int V = 101;

int main(){
	printf("%d\n", V);
	for(int i = 0; i < V; ++i) puts("0");
	printf("1\n0 %d\n", V-1);
}