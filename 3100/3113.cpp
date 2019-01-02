#include <cstdio>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX_P = 32000;
typedef pair<int, int> P;

int main(){
	bool np[MAX_P] = {0, 0,};
	vector<int> prime(1, 2);
	for(int i = 3; i < MAX_P; i += 2){
		if(np[i]) continue;
		prime.push_back(i);
		for(int j = i*i; j < MAX_P; j += i*2)
			np[j] = true;
	}

	int N, M, H;
	unordered_map<int, int> hash;
	vector<int> cnt[50], H2P;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		int A;
		scanf("%d", &A);
		for(int j: prime){
			if(A == 1) break;
			if(A%j == 0){
				if(hash.find(j) == hash.end()){
					hash[j] = H++;
					H2P.push_back(j);
					for(int k = 0; k < N; ++k)
						cnt[k].push_back(0);
				}
				do{
					++cnt[i][hash[j]];
					A /= j;
				}while(A%j == 0);
			}
		}
		if(A > 1){
			if(hash.find(A) == hash.end()){
				hash[A] = H++;
				H2P.push_back(A);
				for(int k = 0; k < N; ++k)
					cnt[k].push_back(0);
			}
			++cnt[i][hash[A]];
		}
	}
	scanf("%d", &M);

	for(int i = 0; i < H; ++i){
		printf("ENTER %d\n", H2P[i]);
		P remain[50];
		for(int j = 0; j < N; ++j)
			remain[j] = P(cnt[j][i], j+1);
		while(1){
			sort(remain, remain+N);
			if(remain[N-1].first == 0) break;
			printf("CLONE");
			for(int j = 0, k = N-1; j < M && remain[k].first > 0; ++j, --k){
				--remain[k].first;
				printf(" %d", remain[k].second);
			}
			puts("");
		}
	}
}