#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 1000;

int main(){
	int N, M, P[MAX];
	scanf("%d %d", &N, &M);
	for(int i = 0; i < M; ++i)
		scanf("%d", P+i);
	sort(P, P+M);
	int r1 = 0, r2 = -1;
	for(int i = 0; i < M; ++i){
		int temp = min(M-i, N)*P[i];
		if(r2 < temp){
			r1 = P[i];
			r2 = temp;
		}
	}
	printf("%d %d\n", r1, r2);
}