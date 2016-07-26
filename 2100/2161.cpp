#include <cstdio>
#include <queue>
using namespace std;

int main(){

	int N;
	scanf("%d", &N);
	queue<int> deck;
	for(int i=1; i<=N; i++)
		deck.push(i);
	while(1){
		printf("%d ", deck.front());
		deck.pop();
		N--;
		if(!N) break;
		deck.push(deck.front());
		deck.pop();
	}

	return 0;
}