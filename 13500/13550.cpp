#include <cstdio>
#include <cmath>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 100000;
const int MAX_VAL = 1000000;
const int MAX_SQRT = 1000;
const int MAX_SQD = (MAX-1)/MAX_SQRT+1;
const int MAX_CAP = MAX_SQRT*MAX_SQD;

int sqrtN;

struct QueryNode{
	int s, e, n;
	QueryNode(): QueryNode(0, 0, -1){}
	QueryNode(int s1, int e1, int n1): s(s1), e(e1), n(n1){}
	bool operator <(const QueryNode &O)const{
		if(s/sqrtN != O.s/sqrtN) return (s/sqrtN < O.s/sqrtN);
		return (e < O.e);
	}
};

int main(){
	int N, M, K, pSum[MAX+1] = {0,};
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N; ++i){
		int val;
		scanf("%d", &val);
		pSum[i+1] = (pSum[i] + val) % K;
	}
	sqrtN = sqrt(N);

	QueryNode Q[MAX];
	scanf("%d", &M);
	for(int i = 0; i < M; ++i){
		int l, r;
		scanf("%d %d", &l, &r);
		Q[i] = QueryNode(l-1, r+1, i);
	}
	sort(Q, Q+M);

	list<int> pos[MAX_VAL];
	int cnt[MAX_CAP] = {0,}, sqd[MAX_SQD] = {0,};
	int s = 0, e = 0, result[MAX];
	for(int i = 0; i < M; ++i){
		while(Q[i].s < s){
			int val = --s;
			auto &li = pos[pSum[val]];
			int d;
			if(!li.empty()){
				d = li.back() - li.front();
				--cnt[d];
				--sqd[d/MAX_SQRT];
			}
			li.push_front(val);
			d = li.back() - li.front();
			++cnt[d];
			++sqd[d/MAX_SQRT];
		}
		while(e < Q[i].e){
			int val = e++;
			auto &li = pos[pSum[val]];
			int d;
			if(!li.empty()){
				d = li.back() - li.front();
				--cnt[d];
				--sqd[d/MAX_SQRT];
			}
			li.push_back(val);
			d = li.back() - li.front();
			++cnt[d];
			++sqd[d/MAX_SQRT];
		}
		while(Q[i].s > s){
			int val = s++;
			auto &li = pos[pSum[val]];
			int d = li.back() - li.front();
			--cnt[d];
			--sqd[d/MAX_SQRT];
			li.pop_front();
			if(!li.empty()){
				d = li.back() - li.front();
				++cnt[d];
				++sqd[d/MAX_SQRT];
			}
		}
		while(e > Q[i].e){
			int val = --e;
			auto &li = pos[pSum[val]];
			int d = li.back() - li.front();
			--cnt[d];
			--sqd[d/MAX_SQRT];
			li.pop_back();
			if(!li.empty()){
				d = li.back() - li.front();
				++cnt[d];
				++sqd[d/MAX_SQRT];
			}
		}

		int temp = 0;
		for(int j = MAX_SQD-1; j >= 0; --j){
			if(sqd[j] == 0) continue;
			for(int k = MAX_SQRT-1; k >= 0; --k){
				if(cnt[j*MAX_SQRT + k] > 0){
					temp = j*MAX_SQRT + k;
					break;
				}
			}
			break;
		}
		result[Q[i].n] = temp;
	}
	for(int i = 0; i < M; ++i)
		printf("%d\n", result[i]);
}