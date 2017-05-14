#include <cstdio>
#include <tuple>
#include <algorithm>
using namespace std;
typedef tuple<int, int, int> Player;

int main(){
	int N;
	scanf("%d", &N);
	Player p[10000];
	for(int i=0; i<N; i++){
		int A, B;
		scanf("%d %d", &A, &B);
		p[i] = Player(A, B, i+1);
	}
	sort(p, p+N, [](const Player &a, const Player &b){
		return get<0>(a) + get<1>(a)*get<0>(b) > get<0>(b) + get<1>(b)*get<0>(a);
	});
	for(int i=0; i<N; i++)
		printf("%d\n", get<2>(p[i]));
}