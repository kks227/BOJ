#include <cstdio>
#include <vector>
#include <set>
using namespace std;
const int P_MAX = 5000000;

int main(){
	bool np[P_MAX] = {1, 1,};
	vector<int> p(1, 2);
	for(int i=4; i<P_MAX; i+=2)
		np[i] = true;
	for(int i=3; i<P_MAX; i+=2){
		if(np[i]) continue;
		p.push_back(i);
		for(long long j=1LL*i*i; j<P_MAX; j+=i*2)
			np[j] = true;
	}
	set<int> S[2];

	int N;
	long long score[2] = {0};
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		for(int j=0; j<2; j++){
			int k;
			scanf("%d", &k);
			if(np[k]){
				if(S[!j].size() < 3) score[!j] += 1000;
				else{
					auto iter = S[!j].end();
					for(int l=0; l<3; l++, iter--);
					score[!j] += *iter;
				}
			}
			else if(S[0].find(k) != S[0].end() || S[1].find(k) != S[1].end()) score[j] -= 1000;
			else S[j].insert(k);
		}
	}
	if(score[0] == score[1]) puts("우열을 가릴 수 없음");
	else puts(score[0] > score[1] ? "소수의 신 갓대웅" : "소수 마스터 갓규성");
}