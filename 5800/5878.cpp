#include <cstdio>
#include <vector>
#include <deque>
#include <set>
#include <algorithm>
#include <utility>
using namespace std;
const int MAX = 100000;
typedef pair<int, int> P;

int main(){
	int N, L, H[MAX], W[MAX];
	long long pSum[MAX+1] = {0}, dp[MAX];
	scanf("%d %d", &N, &L);
	for(int i = 0; i < N; ++i){
		scanf("%d %d", H+i, W+i);
		pSum[i+1] = pSum[i] + W[i];
	}

	multiset<long long> S;
	deque<P> DQ;
	dp[0] = H[0];
	S.insert(H[0]);
	DQ.push_back(P(0, H[0]));
	for(int i = 1; i < N; ++i){

		int sTemp = i, hTemp;
		while(!DQ.empty() && DQ.back().second < H[i]){
			sTemp = DQ.back().first;
			S.erase( S.find(DQ.back().second + (sTemp>0 ? dp[sTemp-1] : 0)) );
			DQ.pop_back();
		}
		DQ.push_back(P(sTemp, H[i]));
		S.insert( H[i] + (sTemp>0 ? dp[sTemp-1] : 0) );

		while(pSum[i+1] - pSum[DQ.front().first] > L){
			sTemp = DQ.front().first;
			hTemp = DQ.front().second;
			S.erase( S.find(DQ.front().second + (sTemp>0 ? dp[sTemp-1] : 0)) );
			DQ.pop_front();
			if(!DQ.empty() && pSum[i+1] - pSum[DQ.front().first] > L) continue;

			int next = DQ.empty() ? i : DQ.front().first;
			int lo = sTemp, hi = next;
			while(lo+1 < hi){
				int mid = (lo+hi)/2;
				(pSum[i+1] - pSum[mid] > L ? lo : hi) = mid;
			}
			if(hi == next) continue;

			DQ.push_front(P(hi, hTemp));
			S.insert(hTemp + dp[hi-1]);
		}

		dp[i] = *S.begin();
	}
	printf("%lld\n", dp[N-1]);
}