#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1003001;

int main(){
	int N;
	bool np[MAX+1] = {0};
	vector<int> result(1, 2);
	for(int i=3; i<=MAX; i+=2){
		if(np[i]) continue;
		int a = i, b = 0;
		while(a){
			b = b*10 + a%10;
			a /= 10;
		}
		if(b == i) result.push_back(i);
		if(1LL*i*i > MAX) continue;
		for(int j=i*i; j<=MAX; j+=i*2)
			np[j] = true;
	}
	scanf("%d", &N);
	printf("%d\n", *lower_bound(result.begin(), result.end(), N));
}