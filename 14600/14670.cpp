#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, M[101], R;
	fill(M, M+101, -1);
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int Me, Mn;
		scanf("%d %d", &Me, &Mn);
		M[Me] = Mn;
	}
	scanf("%d", &R);
	for(int i=0; i<R; i++){
		int L, S[100];
		bool flag = true;
		scanf("%d", &L);
		for(int j=0; j<L; j++){
			scanf("%d", S+j);
			if(M[S[j]] < 0) flag = false;
		}
		if(!flag) puts("YOU DIED");
		else{
			for(int j=0; j<L; j++)
				printf("%d ", M[S[j]]);
			puts("");
		}
	}
}