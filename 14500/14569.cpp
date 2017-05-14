#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, M, k[1000];
	bool t[1000][50] = {0};
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", k+i);
		for(int j=0; j<k[i]; j++){
			int t1;
			scanf("%d", &t1);
			t[i][t1-1] = true;
		}
	}

	scanf("%d", &M);
	for(int i=0; i<M; i++){
		int result = 0, p, q[50];
		scanf("%d", &p);
		for(int j=0; j<p; j++){
			scanf("%d", q+j);
			q[j]--;
		}
		for(int j=0; j<N; j++){
			int cnt = 0;
			for(int l=0; l<p; l++)
				if(t[j][q[l]]) cnt++;
			if(cnt == k[j]) result++;
		}
		printf("%d\n", result);
	}
}