#include <cstdio>
#include <queue>
#include <functional>
using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	priority_queue<int, vector<int>, greater<int> > cards;
	for(int i=0; i<N; i++){
		int a;
		scanf("%d", &a);
		cards.push(a);
	}
	int result = 0;
	while(cards.size() > 1){
		int sum = cards.top();
		cards.pop();
		sum += cards.top();
		cards.pop();
		result += sum;
		cards.push(sum);
	}
	printf("%d\n", result);
}