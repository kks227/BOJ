#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int card[20];
	for(int i=0; i<20; i++)
		card[i] = i+1;
	for(int i=0; i<10; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		reverse(card+a-1, card+b);
	}
	for(int i=0; i<20; i++)
		printf("%d ", card[i]);
}