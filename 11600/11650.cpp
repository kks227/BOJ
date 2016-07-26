#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

int main(){
	int N, x, y;
	pair<int, int> C[100000];
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d %d", &x, &y);
		C[i] = pair<int, int>(x, y);
	}
	sort(C, C+N);
	for(int i=0; i<N; i++)
		printf("%d %d\n", C[i].first, C[i].second);
}