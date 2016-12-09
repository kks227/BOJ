#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N, result = 0;
		scanf("%d", &N);
		for(int i=0; i<N; i++){
			int temp = 0;
			for(int j=0; j<3; j++){
				int val;
				scanf("%d", &val);
				temp = max(temp, val);
			}
			result += temp;
		}
		printf("%d\n", result);
	}
}