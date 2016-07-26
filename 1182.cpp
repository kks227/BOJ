#include <cstdio>
using namespace std;

int N, S, ele[20];
int cnt, currentSum;

void DFS(int current){
	if(current >= N) return;

	if(currentSum+ele[current] == S) cnt++;
	DFS(current+1);
	currentSum += ele[current];
	DFS(current+1);
	currentSum -= ele[current];
}

int main(){

	scanf("%d %d", &N, &S);
	for(int i=0; i<N; i++)
		scanf("%d", ele+i);

	DFS(0);
	printf("%d\n", cnt);
	
    return 0;
}