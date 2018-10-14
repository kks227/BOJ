#include <cstdio>
#include <cmath>
#include <vector>
#include <deque>
#include <set>
#include <algorithm>
#include <utility>
using namespace std;
const int MAX = 100000;
typedef pair<int, int> P;

int main(){
	int N, H[MAX], W[MAX];
	long long pSum[MAX+1] = {0}, dp[MAX];
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%d %d", W+i, H+i);
		pSum[i+1] = pSum[i] + W[i];
	}

	int lo = 0, hi = 10000 * (int)(sqrt(N)+1);
	while(lo+1 < hi){
		int mid = (lo+hi)/2;

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

			while(pSum[i+1] - pSum[DQ.front().first] > mid){
				sTemp = DQ.front().first;
				hTemp = DQ.front().second;
				S.erase( S.find(DQ.front().second + (sTemp>0 ? dp[sTemp-1] : 0)) );
				DQ.pop_front();
				if(!DQ.empty() && pSum[i+1] - pSum[DQ.front().first] > mid) continue;

				int next = DQ.empty() ? i : DQ.front().first;
				int lo2 = sTemp, hi2 = next;
				while(lo2+1 < hi2){
					int mid2 = (lo2+hi2)/2;
					(pSum[i+1] - pSum[mid2] > mid ? lo2 : hi2) = mid2;
				}
				if(hi2 == next) continue;

				DQ.push_front(P(hi2, hTemp));
				S.insert(hTemp + dp[hi2-1]);
			}

			dp[i] = *S.begin();
		}

		(dp[N-1] <= mid ? hi : lo) = mid;
	}
	printf("%d\n", hi);
}