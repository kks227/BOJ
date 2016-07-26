#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		bool map[100] = {0};
		int N;
		scanf("%d", &N);
		for(int i=1; i<=N; i++)
			for(int j=i-1; j<N; j+=i)
				map[j] = !map[j];
		int result = 0;
		for(int i=0; i<N; i++)
			result += map[i];
		printf("%d\n", result);
	}
}