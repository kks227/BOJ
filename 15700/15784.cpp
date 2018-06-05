#include <cstdio>
using namespace std;

int main(){
	int N, r, c, X[1000][1000];
	scanf("%d %d %d", &N, &r, &c);
	r--; c--;
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			scanf("%d", &X[i][j]);
	bool result = true;
	for(int i=0; i<N; i++){
		if(i != r && X[r][c] < X[i][c]) result = false;
		if(i != c && X[r][c] < X[r][i]) result = false;
	}
	puts(result ? "HAPPY" : "ANGRY");
}