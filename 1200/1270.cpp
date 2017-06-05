#include <cstdio>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N;
		unordered_map<long long, int> M;
		scanf("%d", &N);
		for(int i=0; i<N; i++){
			long long k;
			scanf("%lld", &k);
			auto finder = M.find(k);
			if(finder == M.end()) M[k] = 1;
			else finder->second++;
		}
		bool success = false;
		for(auto &p: M){
			if(p.second > N/2){
				printf("%lld\n", p.first);
				success = true;
				break;
			}
		}
		if(!success) puts("SYJKGW");
	}
}