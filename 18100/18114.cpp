#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 5000;

int main(){
	int N, C, w[MAX];
	scanf("%d %d", &N, &C);
	for(int i = 0; i < N; ++i)
		scanf("%d", w+i);
	sort(w, w+N);
	for(int i = 0; i < N && w[i] <= C; ++i){
		if(w[i] == C){
			puts("1");
			return 0;
		}
		for(int j = i+1; j < N && w[i] + w[j] <= C; ++j){
			if(w[i] + w[j] == C){
				puts("1");
				return 0;
			}
			int K = C - w[i] - w[j];
			if(K > w[j] && binary_search(w+j+1, w+N, K)){
				puts("1");
				return 0;
			}
		}
	}
	puts("0");
}