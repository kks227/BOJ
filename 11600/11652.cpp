#include <cstdio>
#include <map>
using namespace std;

int main(){
	int N;
	map<long long, int> M;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		long long card;
		scanf("%lld", &card);
		map<long long, int>::iterator I = M.find(card);
		if(I == M.end()) M[card] = 1;
		else I->second++;
	}
	int max = 0;
	long long result;
	for(auto& p: M)
		if(p.second > max || p.second == max && result > p.first){
			max = p.second;
			result = p.first;
		}
	printf("%lld\n", result);
}