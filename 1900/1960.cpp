#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

int main(){
	int N, R[500], C[500];
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", R+i);
	for(int i=0; i<N; i++)
		scanf("%d", C+i);

	bool M[500][500] = {0}, fail = false;
	for(int i=0; i<N; i++){
		if(R[i] == 0) continue;
		int S[500];
		for(int j=0; j<N; j++)
			S[j] = C[j]*1000 + j;
		sort(S, S+N, greater<int>());
		for(int k=0; k<N; k++){
			int j = S[k] % 1000;
			if(C[j] == 0) continue;
			R[i]--;
			C[j]--;
			M[i][j] = 1;
			if(R[i] == 0) break;
		}
		if(R[i] > 0){
			fail = true;
			break;
		}
	}
	for(int i=0; i<N; i++)
		if(C[i] > 0){
			fail = true;
			break;
		}

	if(fail) puts("-1");
	else{
		puts("1");
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++)
				printf("%d", M[i][j]);
			puts("");
		}
	}
}