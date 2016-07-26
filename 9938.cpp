#include <cstdio>
#include <algorithm>
using namespace std;

int uf[300000];
bool filled[300000];

int uf_find(int n){
	if(uf[n] < 0) return n;
	return uf[n] = uf_find(uf[n]);
}

bool uf_union(int n, int m){
	n = uf_find(n);
	m = uf_find(m);
	if(n == m) return false;
	uf[n] = m;
	return true;
}



int main(){
	int N, L;
	scanf("%d %d", &N, &L);
	fill(uf, uf+L, -1);
	for(int i=0; i<N; i++){
		int A, B;
		scanf("%d %d", &A, &B);
		A--; B--;
		if(!filled[A]){
			puts("LADICA");
			filled[A] = true;
			uf_union(A, B);
		}
		else if(!filled[B]){
			puts("LADICA");
			filled[B] = true;
			uf_union(B, A);
		}
		else if(!filled[uf_find(A)]){
			puts("LADICA");
			filled[uf[A]] = true;
			uf_union(A, B);
		}
		else if(!filled[uf_find(B)]){
			puts("LADICA");
			filled[uf[B]] = true;
			uf_union(B, A);
		}
		else puts("SMECE");
	}
}