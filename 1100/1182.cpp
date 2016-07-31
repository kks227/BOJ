#include <cstdio>
using namespace std;

int N, S, ele[20];
int cnt, currentSum;

// ele의 첫 번째 원소부터 포함하거나 포함하지 않으며 재귀호출
void DFS(int current){
	// N개 원소를 다 사용했으면 돌아감
	if(current >= N) return;

	// 만약 현재 합이 S와 같다면 결과++
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
	// 모든 원소를 포함/미포함시켜가 보며 완전탐색
	DFS(0);
	printf("%d\n", cnt);
}