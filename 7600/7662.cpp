#include <cstdio>
#include <set>
using namespace std;

int main(){

	int T, K, N;
	char ope;
	scanf("%d", &T);
	multiset<int> depq;
	multiset<int>::iterator iter;
	for(int i=0; i<T; i++){
		scanf("%d", &K);
		depq.clear();
		for(int j=0; j<K; j++){
			getchar();
			ope = getchar();
			if(ope == 'I'){
				scanf("%d", &N);
				depq.insert(N);
			}
			else{
				scanf("%d", &N);
				if(depq.empty()) continue;
				if(N == 1){
					iter = depq.end();
					depq.erase(--iter);
				}
				else depq.erase(depq.begin());
			}
		}
		if(depq.empty()) printf("EMPTY\n");
		else{
			iter = depq.end();
			iter--;
			printf("%d ", *iter);
			iter = depq.begin();
			printf("%d\n", *iter);
		}
	}

	return 0;
}