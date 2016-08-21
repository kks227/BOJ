#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	for(int t=1; ; t++){
		int L, P, V;
		scanf("%d %d %d", &L, &P, &V);
		if(V == 0) break;
		printf("Case %d: %d\n", t, V/P*L + min(V%P, L)); 
	}
}