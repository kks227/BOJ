#include <cstdio>
#include <cstring>
using namespace std;

int uf[100001];

int uf_find(int a){
	if(uf[a] < 0) return a;
	return uf[a] = uf_find(uf[a]);
}

bool uf_union(int a, int b){
	a = uf_find(a);
	b = uf_find(b);
	if(a == b) return false;
	uf[b] = a;
	return true;
}

int main(){
	int G, P, result = 0;
	scanf("%d %d", &G, &P);
	memset(uf, -1, sizeof(uf));
	bool fail = false;
	for(int i=0; i<P; i++){
		int g, root;
		scanf("%d", &g);
		if(fail) continue;

		root = uf_find(g);
		if(root > 0){
			result++;
			uf_union(root-1, root);
		}
		else fail = true;
	}
	printf("%d\n", result);
}