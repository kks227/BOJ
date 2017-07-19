#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N, arr[1000], K = -INF;
		scanf("%d", &N);
		bool allMinus = true;
		for(int i=0; i<N; i++){
			scanf("%d", arr+i);
			if(arr[i] > 0) allMinus = false;
			K = max(K, arr[i]);
		}
		if(allMinus){
			printf("%d\n", K);
			continue;
		}

		int sum = 0, result = 0;
		for(int i=0; i<N; i++){
			sum += arr[i];
			if(sum < 0) sum = 0;
			result = max(result, sum);
		}
		printf("%d\n", result);
	}
}