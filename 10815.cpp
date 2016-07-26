#include <cstdio>
#include <set>
using namespace std;

int main(){
	int N, M, n;
	set<int> cards;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", &n);
		cards.insert(n);
	}
	scanf("%d", &M);
	for(int i=0; i<M; i++){
		scanf("%d", &n);
		printf("%d ", cards.count(n));
	}
}