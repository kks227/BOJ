#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

int K;
set<int> val[9];

void bruteForce(int limit){
	if(limit == 0) return;
	if(!val[limit].empty()) return;
	int KK = K;
	for(int i=1; i<limit; i++)
		KK = KK*10 + K;
	val[limit].insert(KK);
	val[limit].insert(-KK);
	for(int i=1; i<limit; i++){
		bruteForce(i);
		bruteForce(limit-i);
		for(int A: val[i])
			for(int B: val[limit-i]){
				if(i<=limit/2){
					val[limit].insert(A+B);
					val[limit].insert(A-B);
					val[limit].insert(A*B);
				}
				if(B) val[limit].insert(A/B);
			}
	}
}

int main(){
	int N, dest;
	scanf("%d %d", &K, &N);
	val[0].insert(0);
	bruteForce(8);
	for(int i=0; i<N; i++){
		scanf("%d", &dest);
		int result = 0;
		for(; result<=8 && val[result].find(dest)==val[result].end(); result++);
		if(result == 9) puts("NO");
		else printf("%d\n", result);
	}
}