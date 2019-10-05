#include <cstdio>
#include <set>
using namespace std;

int main(){
	for(int t = 0; t < 3; ++t){
		int N;
		scanf("%d", &N);
		multiset<long long> S;
		for(int i = 0; i < N; ++i){
			long long val;
			scanf("%lld", &val);
			if(val != 0) S.insert(val);
		}
		char result = '0';
		while(!S.empty()){
			auto iter1 = S.begin(), iter2 = S.end(); --iter2;
			if(*iter1 > 0){
				result = '+';
				break;
			}
			if(*iter2 < 0){
				result = '-';
				break;
			}
			long long temp = *iter1 + *iter2;
			S.erase(iter1); S.erase(iter2);
			if(temp != 0) S.insert(temp);
		}
		printf("%c\n", result);
	}
}