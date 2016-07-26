#include <cstdio>
#include <cstring>
using namespace std;

int uf[200];

int find(int n){
	if(uf[n] < 0) return n;
	return uf[n] = find(uf[n]);
}

void merge(int m, int n){
	int mRoot = find(m);
	int nRoot = find(n);
	if(mRoot == nRoot) return;
	if(uf[mRoot] < uf[nRoot]){
		uf[mRoot] += uf[nRoot];
		uf[nRoot] = mRoot;
	}
	else{
		uf[nRoot] += uf[mRoot];
		uf[mRoot] = nRoot;
	}
}

int main(){

	int N, M, isConnected;
	scanf("%d %d", &N, &M);
	memset(uf, -1, sizeof(int)*200);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			scanf("%d", &isConnected);
			if(i<j) continue;

			if(isConnected) merge(i, j);
		}
	}

	bool result = true;
	int target, current;
	scanf("%d", &target);
	target = find(target-1);
	for(int i=1; i<M; i++){
		scanf("%d", &current);
		if(!result) continue;
		current = find(current-1);
		if(current != target) result = false;
	}
	printf("%s\n", result?"YES":"NO");

	return 0;
}