#include <cstdio>
#include <queue>
using namespace std;

int main(){

	int N;
	scanf("%d", &N);
	deque<int> card;
	for(int i=1; i<=N; i++)
		card.push_back(i);

	for(int i=N-1; i>0; i--){
		card.pop_front();
		card.push_back(card[0]);
		card.pop_front();
	}
	printf("%d\n", card[0]);

	return 0;
}