#include <cstdio>
using namespace std;

int main(){
	int N, p[500][2], M;
	bool dead[501] = {1};
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d %d", &p[i][0], &p[i][1]);
	scanf("%d", &M);
	for(int i=0; i<M; i++){
		int k;
		scanf("%d", &k);
		dead[k] = true;
	}
	int result = 0;
	for(int i=0; i<N; i++)
		if(!dead[i+1] && !dead[p[i][0]] && !dead[p[i][1]]) result++;
	printf("%d\n", result);
}