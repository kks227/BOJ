#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 100000;
typedef pair<int, int> P;

int main(){
	int N, M;
	P p[MAX];
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; ++i)
		scanf("%d %d", &p[i].second, &p[i].first);
	sort(p, p+N);

	int pSum[MAX+1] = {0,}, result = -1;
	for(int i = 0; i < N; ++i)
		pSum[i+1] = pSum[i] + p[i].second;
	for(int i = 0, j; i < N; ){
		int need = M - pSum[i], price = 0;
		for(j = i+1; j < N && p[j].first == p[i].first; ++j);
		for(int k = 0; k < j-i; ++k){
			price += p[i].first;
			if(need <= pSum[j] - pSum[j-k-1]){
				if(result == -1) result = price;
				else result = min(price, result);
			}
		}
		i = j;
	}
	printf("%d\n", result);
}