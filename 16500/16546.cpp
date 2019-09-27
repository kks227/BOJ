#include <cstdio>
using namespace std;
const int MAX = 1<<15;

int main(){
	int N;
	scanf("%d", &N);
	bool check[MAX] = {false,};
	for(int i = 0; i < N-1; ++i){
		int val;
		scanf("%d", &val);
		check[val-1] = true;
	}
	for(int i = 0; i < N; ++i)
		if(!check[i]) printf("%d\n", i+1);
}