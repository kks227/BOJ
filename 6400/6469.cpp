#include <cstdio>
using namespace std;

int main(){
	int N, M;
	while(scanf("%d %d", &N, &M) > 0){
		bool used[100000] = {0};
		int cnt = 0, k = 0;
		while(!used[k]){
			cnt++;
			used[k] = true;
			k = (k+N) % M;
		}
		printf("%10d%10d %s Choice\n\n", N, M, cnt==M ? "Good" : "Bad");
	}
}