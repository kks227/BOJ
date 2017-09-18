#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

inline int score(int a, int b){
	if(a == b) return 9+a;
	return (a+b)%10;
}

int main(){
	int A, B, s = {0};
	scanf("%d %d", &A, &B);
	vector<int> cards;
	for(int i=0; i<20; i++)
		cards.push_back(i/2+1);
	s = score(A, B);
	cards.erase(find(cards.begin(), cards.end(), A));
	cards.erase(find(cards.begin(), cards.end(), B));

	int win = 0;
	for(int i=0; i<17; i++)
		for(int j=i+1; j<18; j++)
			if(s > score(cards[i], cards[j])) win++;
	printf("%.3lf\n", win/153.0);
}