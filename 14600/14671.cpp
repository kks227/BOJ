#include <cstdio>
using namespace std;

int main(){
	int R, C, K;
	bool flag[2][2] = {false}, result = true;
	scanf("%d %d %d", &R, &C, &K);
	for(int i=0; i<K; i++){
		int r, c;
		scanf("%d %d", &r, &c);
		flag[r%2][c%2] = true;
	}
	for(int i=0; i<2; i++)
		for(int j=0; j<2; j++)
			result &= flag[i][j];
	puts(result ? "YES" : "NO");
}