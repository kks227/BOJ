#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1e8;

int main(){
	vector<int> prime(1, 2);
	bool np[MAX/2] = {true,};
	int P = 1;
	for(int i=3; i<=MAX; i+=2){
		if(np[i/2]) continue;
		prime.push_back(i);
		P++;
		for(long long j=1LL*i*i; j<=MAX; j+=i*2) np[j/2] = true;
	}

	int N;
	while(scanf("%d", &N) > 0){
		if(N < 8){
			puts("Impossible.");
			continue;
		}
		
		if(N%2){
			printf("2 3 ");
			N -= 5;
		}
		else{
			printf("2 2 ");
			N -= 4;
		}
		for(int i: prime){
			int j = N-i;
			if(find(prime.begin(), prime.end(), j) != prime.end()){
				printf("%d %d\n", i, j);
				break;
			}
		}
	}
}