#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 1000;
const int MAX_H = 100;
const int INF = 1e9;

int main(){
	int N, H[MAX], result = INF;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		scanf("%d", H+i);
	for(int i = 0; i <= MAX_H; ++i){
		int temp = 0;
		for(int j = 0; j < N; ++j){
			if(H[j] < i) temp += (i-H[j])*(i-H[j]);
			else if(H[j] > i+17) temp += (i+17-H[j])*(i+17-H[j]);
		}
		result = min(temp, result);
	}
	printf("%d\n", result);
}