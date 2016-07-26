#include <cstdio>
using namespace std;

int main(){

	int V, A=0, B=0;
	scanf("%d\n", &V);
	for(int i=0; i<V; i++){
		if(getchar()=='A') A++;
		else B++;
	}
	if(A>B) puts("A");
	else if(A<B) puts("B");
	else puts("Tie");

	return 0;
}