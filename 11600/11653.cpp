#include <cstdio>
#include <vector>
using namespace std;
const int MAX = 5000;

int main(){
	int N;
	scanf("%d", &N);
	bool np[MAX] = {1, 1};
	vector<int> p(1, 2);
	for(int i=4; i<MAX; i+=2)
		np[i] = true;
	for(int i=3; i<MAX; i+=2){
		if(np[i]) continue;
		p.push_back(i);
		for(int j=i*i; j<MAX; j+=i*2)
			np[j] = true;
	}

	int i = 0;
	while(N > 1 && i < p.size()){
		if(N%p[i] == 0){
			N /= p[i];
			printf("%d\n", p[i]);
		}
		else i++;
	}
	if(N > 1) printf("%d\n", N);
}